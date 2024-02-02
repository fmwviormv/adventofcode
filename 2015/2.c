#include <stdio.h>

int
main(void)
{
	long paper = 0, ribbon = 0;
	for (;;) {
		long x, y, z, t = scanf("%ldx%ldx%ld", &x, &y, &z);
		if (t == EOF || (t == 0 && feof(stdin))) break;
		if (t != 3) return 1;
		if (y < x) { t = y; y = x; x = t; }
		if (z < y) { t = y; y = z; z = t; }
		paper += 3 * x*y + 2 * (x+y) * z;
		ribbon += 2 * (x+y) + x*y*z;
	}
	printf("%ld\n%ld\n", paper, ribbon);
	return 0;
}
