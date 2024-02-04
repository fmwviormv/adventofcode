#include <stdio.h>
#include <string.h>

enum { size = 100, end = 2503 };

int
main(void)
{
	int n = 0, best = 0;
	struct { int speed, fly, rest; } a[size];
	int record[end];
	memset(record, 0, sizeof(record));
	for (char nl, buf[1024]; fgets(buf, sizeof(buf), stdin); ++n) {
	if (n >= size || sscanf(buf, "%*[^ ] can fly %d km/s for %d "
	    "secon%*[ds], but then must rest for %d secon%*[ds].%c",
	    &a[n].speed, &a[n].fly, &a[n].rest, &nl) != 4 || nl != '\n')
		return 1;
	}
	for (int cnt = 0; cnt < 2; ++cnt)
	for (int p, i = 0; i < n; ++i) {
		for (int c, x = 0, t = p = 0; t < end; ) {
			for (c = a[i].fly; --c >= 0 && t < end; ++t) {
				x += a[i].speed;
				if (cnt) p += (record[t] == x);
				else if (record[t] < x) record[t] = x;
			}
			for (c = a[i].rest; --c >= 0 && t < end; ++t) {
				if (cnt) p += (record[t] == x);
				else if (record[t] < x) record[t] = x;
			}
		}
		if (best < p) best = p;
	}
	printf("%d\n%d\n", record[end - 1], best);
	return 0;
}
