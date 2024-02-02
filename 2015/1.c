#include <stdio.h>

int
main(void)
{
	long floor = 0, pos = 0;
	for (long i = 0; ; ++i) {
		switch (getchar()) {
		case '(': ++floor; break;
		case ')': --floor; break;
		case EOF:
			printf("%ld\n%ld\n", floor, pos);
			return 0;
		default: return 1;
		}
		if (floor == -1 && !pos)
			pos = i + 1;
	}
}
