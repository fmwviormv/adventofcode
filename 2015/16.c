#include <stdio.h>
#include <string.h>

enum { size = 500 };

int
main(void)
{
	int match_1 = 0, match_2 = 0;
	for (char buf[1024]; fgets(buf, sizeof(buf), stdin); ) {
		int n, valid_1 = 1, valid_2 = 1;
		const char *t = strtok(buf, ":");
		if (t == NULL || sscanf(t, "Sue %d", &n) != 1 ||
		    n <= 0 || n > size)
			return 1;
		while ((t = strtok(NULL, "\n,")) != NULL) {
			int x, p1 = 1, p2 = 1;
			if (sscanf(t, " children: %d", &x) == 1)
				p1 = p2 = (x == 3);
			else if (sscanf(t, " cats: %d", &x) == 1)
				p1 = (x == 7), p2 = (x > 7);
			else if (sscanf(t, " samoyeds: %d", &x) == 1)
				p1 = p2 = (x == 2);
			else if (sscanf(t, " pomeranians: %d", &x) == 1)
				p1 = (x == 3), p2 = (x < 3);
			else if (sscanf(t, " akitas: %d", &x) == 1)
				p1 = p2 = (x == 0);
			else if (sscanf(t, " vizslas: %d", &x) == 1)
				p1 = p2 = (x == 0);
			else if (sscanf(t, " goldfish: %d", &x) == 1)
				p1 = (x == 5), p2 = (x < 5);
			else if (sscanf(t, " trees: %d", &x) == 1)
				p1 = (x == 3), p2 = (x > 3);
			else if (sscanf(t, " cars: %d", &x) == 1)
				p1 = p2 = (x == 2);
			else if (sscanf(t, " perfumes: %d", &x) == 1)
				p1 = p2 = (x == 1);
			valid_1 = (valid_1 && p1);
			valid_2 = (valid_2 && p2);
		}
		if (valid_1) { if (match_1) return 1; match_1 = n; }
		if (valid_2) { if (match_2) return 1; match_2 = n; }
	}
	printf("%d\n%d\n", match_1, match_2);
	return 0;
}
