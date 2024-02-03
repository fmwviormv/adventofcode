#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { nodes = 8, namesize = 32 };

int		 get(const char *);
int		 gain(void);
void		 check(const char *);
void		 solve(int);

int n;
char names[nodes][namesize];
int graph[nodes][nodes];

int
main(void)
{
	char buf[1024];
	while (fgets(buf, sizeof(buf), stdin)) {
		int x = get(strtok(buf, " "));
		check("would");
		int w = gain();
		check("happiness"); check("units");
		check("by"); check("sitting");
		check("next"); check("to");
		int y = get(strtok(NULL, "."));
		if (strtok(NULL, "\n") != NULL)
			return 1;
		graph[x][y] += w;
		graph[y][x] += w;
	}
	solve(0);
	solve(1);
	return 0;
}

void
solve(int me)
{
	int d[1 << nodes][nodes];
	char dlen[1 << nodes][nodes];
	memset(dlen, 0, sizeof(dlen));
	if (me) {
		for (int x = 0; x < n; ++x) {
			d[1 << x][x] = 0;
			dlen[1 << x][x] = 1;
		}
	} else {
		d[0][n - 1] = 0;
		dlen[0][n - 1] = 1;
	}
	for (int len = 0; ++len < n; )
	for (int m = 0; !(m >> (n-!me)); ++m)
	for (int x = 0; x < n; ++x)
	if (dlen[m][x] == len)
	for (int y = 0; y < n - !me; ++y) {
		int m2 = m | 1 << y, v = d[m][x] + graph[x][y];
		if (m < m2 && (!dlen[m2][y] || d[m2][y] < v)) {
			dlen[m2][y] = len + 1;
			d[m2][y] = v;
		}
	}
	int all = (1 << (n - !me)) - 1;
	if (!me) {
		for (int x = 0; x < n - 1; ++x)
			d[all][x] += graph[n - 1][x];
	}
	int best = 0;
	for (int x = 0; x < n - !me; ++x)
	if (d[all][best] < d[all][x])
		best = x;
	printf("%d\n", d[all][best]);
}

int
get(const char *s)
{
	if (!s) exit(1);
	for (int i = 0; i < n; ++i)
	if (strncmp(names[i], s, sizeof(*names)) == 0)
		return i;
	if (n == nodes || strlen(s) > sizeof(*names))
		exit(1);
	strncpy(names[n], s, sizeof(*names));
	return n++;
}

int
gain(void)
{
	int is_neg = 0, num;
	const char *tok = strtok(NULL, " ");
	if (tok != NULL && strcmp(tok, "lose") == 0)
		is_neg = 1;
	else if (tok == NULL || strcmp(tok, "gain"))
		exit(1);
	tok = strtok(NULL, " ");
	if (tok == NULL || sscanf(tok, "%d", &num) != 1)
		exit(1);
	return is_neg ? -num : num;
}

void
check(const char *x)
{
	const char *tok = strtok(NULL, " ");
	if (!tok || strcmp(tok, x))
		exit(1);
}
