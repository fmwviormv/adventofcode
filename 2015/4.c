#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint_least32_t	 md5a(const char *);

int
main(void)
{
	char buf[64];
	if (!fgets(buf, sizeof(buf), stdin))
		return 1;
	buf[strcspn(buf, "\r\n")] = 0;
	int n = (int)strlen(buf);
	if (n > 40)
		return 1;
	for (unsigned long i5 = 0, i = 0; ++i; ) {
		snprintf(buf + n, sizeof(buf) - n, "%lu", i);
		uint_least32_t a = md5a(buf);
		if (!(a & 0xf0ffff)) {
			if (!i5) {
				printf("%lu\n", i5 = i);
				fflush(stdout);
			}
			if (!(a & 0xffffff)) {
				printf("%lu\n", i);
				return 0;
			}
		}
	}
	return 1;
}

uint_least32_t
md5a(const char *s)
{
	static const int S[64] = {
		7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
		5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
		4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
		6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
	};
	static const uint_least32_t K[64] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
	}, v0[] = {
		0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476
	};
	uint_least32_t	 F, A = v0[0], B = v0[1], C = v0[2], D = v0[3];
	uint_least32_t	 M[16] = { 0 };
	unsigned char	 pad = 0x80;
	for (int i = 0; i < 56; ++i) {
		unsigned char v = (unsigned char)*s;
		if (v) ++s;
		else if (pad) {
			v = pad; pad = 0;
			M[14] = 8 * (uint_least32_t)i;
		}
		M[i >> 2] |= (uint_least32_t)v << (8 * (i & 3));
	}
	for (int g, i = 0; i < 64; ++i) {
		if (i < 32) {
			if (i < 16) {
				F = (B & C) | (~B & D);
				g = i;
			} else {
				F = (D & B) | (~D & C);
				g = (5 * i + 1) & 15;
			}
		} else if (i < 48) {
			F = B ^ C ^ D;
			g = (3 * i + 5) & 15;
		} else {
			F = C ^ (B | ~D);
			g = (7 * i) & 15;
		}
		F += A + K[i] + M[g];
		A = D; D = C; C = B; g = S[i];
		B += (F << g) | (F >> (32 - g));
	}
	return A + v0[0];
}
