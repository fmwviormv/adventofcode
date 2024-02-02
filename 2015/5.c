#include <limits.h>
#include <stdio.h>
#include <string.h>

int
main(void)
{
	unsigned char seen[UCHAR_MAX + 1][UCHAR_MAX/CHAR_BIT + 1];
	unsigned char buf[1024];
	int nice1 = 0, nice2 = 0;
	memset(seen, 0, sizeof(seen));
	while (fgets((char *)buf, sizeof(buf), stdin)) {
		int i, vow = 0, xx = 0, xyxy = 0, nbad = 0, xyx = 0;
		unsigned char x, y, z = 0;
		buf[strcspn((char *)buf, "\r\n")] = 0;
		for (x = *buf, y = buf[i = 1]; x; x = y, y = z) {
			switch (x) {
			case 'a': case 'e':
			case 'i': case 'o':
			case 'u': ++vow; break;
			}
			if (!y) continue;
			xx += (x == y);
			switch (x) {
			case 'a': nbad += (y == 'b'); break;
			case 'c': nbad += (y == 'd'); break;
			case 'p': nbad += (y == 'q'); break;
			case 'x': nbad += (y == 'y'); break;
			}
			if (!(z = buf[++i])) continue;
			xyx += (x == z);
			xyxy += seen[y][z/CHAR_BIT] >> (z%CHAR_BIT) & 1;
			seen[x][y/CHAR_BIT] |= 1U << y%CHAR_BIT;
		}
		for (int i = 0; buf[i]; ++i)
			seen[buf[i]][buf[i + 1] / CHAR_BIT] = 0;
		nice1 += (vow >= 3 && xx && !nbad);
		nice2 += (xyxy && xyx);
	}
	printf("%d\n%d\n", nice1, nice2);
	return 0;
}
