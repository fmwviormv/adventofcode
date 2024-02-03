#include <stdio.h>
#include <string.h>

enum { small = 40, big = 50, bufsize = 128 };

int
main(void)
{
	char buf[big][bufsize];
	int small_len = 0, big_len = 0;
	memset(buf, 0, sizeof(buf));
	if (!fgets(*buf, bufsize, stdin))
		return 1;
	buf[0][strcspn(*buf, "\r\n")] = 0;
	if (!**buf) return 1;
	for (int n_i, i = 0, depleted = 0; i < big; i = n_i) {
		enum { halfsize = bufsize / 2 };
		int j = 0, n = 0;
		n_i = i + 1;
		if (n_i < big) n = (int)strlen(buf[n_i]);
		while (n < bufsize - 4) {
			char ch = buf[i][j];
			if (!ch) {
				if (i == depleted)
					++depleted;
				else if (n < halfsize)
					n_i = i - 1;
				break;
			}
			int cnt = 1;
			while (buf[i][j + cnt] == ch)
				++cnt;
			if (!buf[i][j + cnt] && i != depleted) {
				if (n < halfsize)
					n_i = i - 1;
				break;
			}
			if (cnt > 32) return 1;
			j += cnt;
			if (i + 1 < big) {
				if (cnt > 9)
					buf[i+1][n++] = cnt / 10 + '0';
				buf[i + 1][n++] = cnt % 10 + '0';
				buf[i + 1][n++] = ch;
				buf[i + 1][n] = 0;
			} else big_len += 2 + (cnt > 9);
		}
		if (i == small) small_len += j;
		memmove(buf[i], buf[i] + j, sizeof(*buf) - j);
	}
	printf("%d\n%d\n", small_len, big_len);
	return 0;
}
