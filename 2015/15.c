#include <stdio.h>

enum { size = 4, teaspoons = 100, exact_calories = 500 };
enum { capacity, durability, flavor, texture, calories, properties };

void		 bt(int, int);

int n;
int a[size][properties];
int sum[properties], best, best_exact;

int
main(void)
{
	for (char nl, buf[1024]; fgets(buf, sizeof(buf), stdin); ++n)
	if (n >= size || sscanf(buf, "%*[^:]: capacity %d, "
	    "durability %d, flavor %d, texture %d, calories %d%c",
	    a[n] + capacity, a[n] + durability, a[n] + flavor,
	    a[n] + texture, a[n] + calories, &nl) != 6 || nl != '\n')
		return 1;
	bt(0, teaspoons);
	printf("%d\n%d\n", best, best_exact);
	return 0;
}

void
bt(int x, int rem)
{
	if (x + 1 == n) {
		int score = 1;
		for (int i = 0; i < calories; ++i) {
			int t = sum[i] + rem * a[x][i];
			if (t < 0) return;
			score *= t;
		}
		if (best < score)
			best = score;
		if (sum[calories] + rem * a[x][calories]
		    == exact_calories && best_exact < score)
			best_exact = score;
		return;
	}
	bt(x + 1, rem);
	for (int r = rem; --r >= 0; ) {
		for (int i = 0; i < properties; ++i)
			sum[i] += a[x][i];
		bt(x + 1, r);
	}
	for (int i = 0; i < properties; ++i)
		sum[i] -= rem * a[x][i];
}
