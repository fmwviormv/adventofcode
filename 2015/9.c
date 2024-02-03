#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { nodes = 8, name_len = 32, max_weight = INT_MAX / nodes };

int	 get(const char *);

int n;
char names[nodes][name_len];

int
main(void)
{
	char buf[1024];
	static int graph[nodes][nodes];
	static int path[1 << nodes][nodes], pathlen[1 << nodes];
	while (fgets(buf, sizeof(buf), stdin)) {
		int x = get(strtok(buf, " ")), y, w;
		const char *tok = strtok(NULL, " ");
		if (tok == NULL || strcmp(tok, "to"))
			return 1;
		y = get(strtok(NULL, " "));
		tok = strtok(NULL, "\n");
		if (tok == NULL || sscanf(tok, "= %d", &w) != 1 ||
		    w <= 0 || w > max_weight)
			return 1;
		if (!graph[x][y] || w < graph[x][y])
			graph[x][y] = graph[y][x] = w;
	}
	int all = (1 << n) - 1, result = 0;
	if (n < 2)
		return 1;
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	if (i != j) {
		path[1 << i | 1 << j][j] = graph[i][j];
		pathlen[1 << i | 1 << j] = 1;
	}
	for (int len = 0; ++len < n; )
	for (int m = 0; ++m < all; )
	if (pathlen[m] == len)
	for (int i = 0; i < n; ++i)
	if (path[m][i])
	for (int j = 0; j < n; ++j)
	if (graph[i][j]) {
		int m2 = m | 1 << j, p2 = path[m][i] + graph[i][j];
		if (m < m2 && (!path[m2][j] || p2 < path[m2][j])) {
			path[m2][j] = p2;
			pathlen[m2] = len + 1;
		}
	}
	for (int i = 0; i < n; ++i)
	if (path[all][i] && (!result || path[all][i] < result))
		result = path[all][i];
	printf("%d\n", result);
	for (int len = 0; ++len < n; )
	for (int m = 0; ++m < all; )
	if (pathlen[m] == len)
	for (int i = 0; i < n; ++i)
	if (path[m][i])
	for (int j = 0; j < n; ++j)
	if (graph[i][j]) {
		int m2 = m | 1 << j, p2 = path[m][i] + graph[i][j];
		if (m < m2 && path[m2][j] < p2)
			path[m2][j] = p2;
	}
	for (int i = 0; i < n; ++i)
	if (result < path[all][i])
		result = path[all][i];
	printf("%d\n", result);
	return 0;
}

int
get(const char *x)
{
	if (x == NULL || strlen(x) > sizeof(*names))
		exit(1);
	for (int i = 0; i < n; ++i)
	if (strncmp(names[i], x, sizeof(*names)) == 0)
		return i;
	if (n == nodes)
		exit(1);
	strncpy(names[n], x, sizeof(*names));
	return n++;
}
