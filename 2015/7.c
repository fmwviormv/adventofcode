#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { num_vars = 27 * 27 * 27 };

int		 kw(const char *), atom(const char *);
int		 calc(int, int);

static const char keywords[][8] = {
	"AND", "LSHIFT", "NOT", "OR", "RSHIFT"
};
enum { k_AND, k_LSHIFT, k_NOT, k_OR, k_RSHIFT, k_none };
enum { m_empty, m_loop, m_new, m_calculated };
struct {
	unsigned short v, x, y, mark:8, op:4, ix:1, iy:1;
} var[num_vars];

int
main(void)
{
	char buf[1024];
	while (fgets(buf, sizeof(buf), stdin)) {
		const char *tok = strtok(buf, "\n ");
		int op = kw(tok), x, y = 0, dest;
		if (op < k_none) {
			if (op != k_NOT) return 1;
			x = atom(strtok(NULL, "\n "));
			tok = strtok(NULL, "\n ");
		} else {
			x = atom(tok);
			tok = strtok(NULL, "\n ");
			if (tok != NULL && strcmp(tok, "->")) {
				op = kw(tok);
				if (op == k_none || op == k_NOT)
					return 1;
				y = atom(strtok(NULL, "\n "));
				tok = strtok(NULL, "\n ");
			}
		}
		if (tok == NULL || strcmp(tok, "->")) return 1;
		dest = -atom(strtok(NULL, "\n ")) - 1;
		tok = strtok(NULL, "\n ");
		if (dest < 0 || tok != NULL || var[dest].mark) return 1;
		if ((var[dest].ix = x < 0)) x = -x - 1;
		if ((var[dest].iy = y < 0)) y = -y - 1;
		var[dest].x = x;
		var[dest].y = y;
		var[dest].op = op;
		var[dest].mark = m_new;
	}
	printf("%d\n", calc(0, m_calculated));
	var[1].v = var[0].v;
	var[1].mark = m_calculated + 1;
	printf("%d\n", calc(0, m_calculated + 1));
	return 0;
}

int
kw(const char *s) {
	if (!s) exit(1);
	for (int i = 0; i < k_none; ++i)
		if (strcmp(s, keywords[i]) == 0)
			return i;
	return k_none;
}

int
atom(const char *s)
{
	if (!s) exit(1);
	else if (*s >= '0' && *s <= '9') {
		int result = *s - '0';
		while (*++s) {
			unsigned char d = *s - '0';
			result = 10 * result + d;
			if (d > 9 || (result >> 16)) exit(1);
		}
		return result;
	} else if (*s >= 'a' && *s <= 'z') {
		int result = *s - 'a' + 1;
		while (*++s) {
			unsigned char d = *s - 'a';
			result = 27 * result + d + 1;
			if (d > 26 || result > num_vars) exit(1);
		}
		return -result;
	}
	exit(1);
}

int
calc(int v, int m)
{
	if (var[v].mark < m_new) exit(1);
	for (unsigned short i = v, x, y; ; i = y) {
		var[i].mark = m_loop;
		x = var[i].x;
		if (var[i].ix) {
			if (var[x].mark < m_new) exit(1);
			if (var[x].mark < m) {
				var[y = x].v = i;
				continue;
			}
			x = var[x].v;
		}
		y = var[i].y;
		if (var[i].iy) {
			if (var[y].mark < m_new) exit(1);
			if (var[y].mark < m) {
				var[y].v = i;
				continue;
			}
			y = var[y].v;
		}
		switch (var[i].op) {
		case k_AND: x &= y; break;
		case k_OR: x |= y; break;
		case k_NOT: x = ~x; break;
		case k_LSHIFT: x = y < 16 ? x << y : 0; break;
		case k_RSHIFT: x = y < 16 ? x >> y : 0; break;
		}
		x &= 0xffff;
		y = var[i].v;
		var[i].v = x;
		var[i].mark = m;
		if (i == v) return x;
	}
}
