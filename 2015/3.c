#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { size = 8192 };

void		 solve(const unsigned char *, int, int);
int		 ipcmp(const void *, const void *);

int
main(void)
{
	unsigned char buf[(size + 3) / 4];
	memset(buf, 0, sizeof(buf));
	for (int n = 0; ; ++n) {
		unsigned char t = 0;
		switch (getchar()) {
		case 'v': ++t;
		case '^': ++t;
		case '>': ++t;
		case '<':
			if (n >= size) return 1;
			buf[n >> 2] |= t << (2 * (n & 3));
			break;
		case EOF:
			solve(buf, n, 0);
			solve(buf, n, 1);
			return 0;
		default:
			return 1;
		}
	}
}

void
solve(const unsigned char *s, int n, int p)
{
	int a[size + 1][2], result = 1;
	for (int i = a[0][0] = a[0][1] = 0; i < n; ++i) {
		int t = i < p ? 0 : i - p;
		a[i + 1][0] = a[t][0];
		a[i + 1][1] = a[t][1];
		t = s[i >> 2] >> (2 * (i & 3)) & 3;
		a[i + 1][t >> 1] += t & 1 ? 1 : -1;
	}
	qsort(a, n + 1, sizeof(*a), ipcmp);
	for (int i = 0; i < n; ++i)
		result += (*a[i] != *a[i+1] || a[i][1] != a[i+1][1]);
	printf("%d\n", result);
}

int
ipcmp(const void *x, const void *y)
{
	const int *ix = x, *iy = y;
	if (*ix == *iy) ++ix, ++iy;
	return *ix < *iy ? -1 : *ix > *iy;
}
