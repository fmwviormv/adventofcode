#include <stdio.h>

enum {
	last_row = 999,
	last_col = 999,
	bitsize = 10,
	size = 1 << bitsize
};

unsigned char	*unmask1(int, int, int);
unsigned short	*unmask2(int, int, int);

struct {
	unsigned char	 m[size][size/2];
	unsigned char	 v[size][size];
} map1;

struct {
	unsigned short	 m[size][size/2][2];
	unsigned short	 v[size][size];
} map2;

int
main(void)
{
	static const char fmt[][32] = {
		"toggle %d,%d through %d,%d",
		"turn on %d,%d through %d,%d",
		"turn off %d,%d through %d,%d"
	};
	char buf[1024];
	while (fgets(buf, sizeof(buf), stdin)) {
		int r[2], c[2], t = buf[6] == 'f' ? 2 : buf[6] == 'n';
		if (sscanf(buf, fmt[t], r, c, r + 1, c + 1) != 4 ||
		    *r < 0 || *r > r[1] || r[1] > last_row ||
		    *c < 0 || *c > c[1] || c[1] > last_col)
			return 1;
		++r[1], ++c[1];
		for (int n1, i = *r; i < r[1]; i += n1) {
			n1 = size | i; n1 &= (unsigned)-n1;
			while (r[1] < i + n1) n1 >>= 1;
			for (int n2, j = *c; j < c[1]; j += n2) {
				unsigned char *m1;
				unsigned short *m2;
				n2 = n1 | j; n2 &= (unsigned)-n2;
				while (c[1] < j + n2) n2 >>= 1;
				for (int k = i; k < i + n1; k += n2) {
					m1 = unmask1(n2, k, j);
					m2 = unmask2(n2, k, j);
					if (m1) {
						if (t) *m1 = 4 - t;
						else *m1 ^= 1;
					} else if (t)
						map1.v[k][j] = 2 - t;
					else
						map1.v[k][j] ^= 1;
					if (m2) {
						if (t < 2) m2[1] += 2-t;
						else if (m2[1]) --m2[1];
						else ++m2[0];
					} else if (t < 2)
						map2.v[k][j] += 2 - t;
					else if (map2.v[k][j])
						--map2.v[k][j];
				}
			}
		}
	}
	long long nlights = 0, brightness = 0;
	for (int i = 0; i <= last_row; ++i)
	for (int j = 0; j <= last_col; ++j) {
		(void)unmask1(1, i, j);
		(void)unmask2(1, i, j);
		nlights += map1.v[i][j];
		brightness += map2.v[i][j];
	}
	printf("%lld\n%lld\n", nlights, brightness);
	return 0;
}

unsigned char *
unmask1(int z, int r, int c)
{
	int s;
	for (s = bitsize; (z >> s) != 1; --s) {
		int i = (size + r) >> s, j = c >> s;
		unsigned char x = map1.m[i][j];
		map1.m[i][j] = 0; i <<= 1; j <<= 1;
		if (s == 1) i = (r >> s) << 1;
		if (s == 1) switch (x) {
		case 1:
			map1.v[i][j] ^= 1; map1.v[i][j + 1] ^= 1;
			map1.v[i+1][j] ^= 1; map1.v[i+1][j+1] ^= 1;
			break;
		case 2: case 3:
			map1.v[i][j] = map1.v[i][j + 1] =
			map1.v[i+1][j] = map1.v[i+1][j+1] = x - 2;
			break;
		} else switch (x) {
		case 1:
			map1.m[i][j] ^= 1; map1.m[i][j + 1] ^= 1;
			map1.m[i+1][j] ^= 1; map1.m[i+1][j+1] ^= 1;
			break;
		case 2: case 3:
			map1.m[i][j] = map1.m[i][j + 1] =
			map1.m[i+1][j] = map1.m[i+1][j+1] = x;
			break;
		}
	}
	return s ? &map1.m[(size + r) >> s][c >> s] : NULL;
}

static inline void
update_value(unsigned short *v, unsigned short x, unsigned short y)
{
	if (*v < x) *v = y;
	else *v += y - x;
}

static inline void
update_mask(unsigned short m[2], unsigned short x, unsigned short y)
{
	if (m[1] < x) {
		m[0] += x - m[1];
		m[1] = y;
	} else m[1] += y - x;
}

unsigned short *
unmask2(int z, int r, int c)
{
	int s;
	for (s = bitsize; (z >> s) != 1; --s) {
		int i = (size + r) >> s, j = c >> s;
		unsigned short x, y, *self = map2.m[i][j];
		x = self[0]; y = self[1];
		self[0] = self[1] = 0;
		i <<= 1; j <<= 1;
		if (s == 1) {
			i = (r >> s) << 1;
			update_value(&map2.v[i][j], x, y);
			update_value(&map2.v[i][j + 1], x, y);
			update_value(&map2.v[i + 1][j], x, y);
			update_value(&map2.v[i + 1][j + 1], x, y);
		} else {
			update_mask(map2.m[i][j], x, y);
			update_mask(map2.m[i][j + 1], x, y);
			update_mask(map2.m[i + 1][j], x, y);
			update_mask(map2.m[i + 1][j + 1], x, y);
		}
	}
	return s ? map2.m[(size + r) >> s][c >> s] : NULL;
}
