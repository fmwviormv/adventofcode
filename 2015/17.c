#include <stdio.h>
#include <string.h>

enum { size = 50, liters = 150 };

int
main(void)
{
	int a[size], d[size][liters], n = 0;
	for (char nl, buf[1024]; fgets(buf, sizeof(buf), stdin); ++n)
	if (n >= size || sscanf(buf, "%d%c", &a[n], &nl) != 2 ||
	    a[n] <= 0 || nl != '\n') return 1;
	memset(d, 0, sizeof(d));
	for (int i = 0; i < n; ++i) {
		int step = a[i];
		if (step > liters) continue;
		for (int j = n - 1; --j >= 0; )
		for (int k = liters - step; --k >= 0; )
			d[j + 1][k + step] += d[j][k];
		++d[0][step - 1];
	}
	int total_count = 0, min_count = 0;
	for (int i = n; --i >= 0; )
	if (d[i][liters - 1])
		total_count += min_count = d[i][liters - 1];
	printf("%d\n%d\n", total_count, min_count);
	return 0;
}
