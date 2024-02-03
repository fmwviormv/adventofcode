#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { size = 8 };

const char	*next(char *);
void		 half_next(char *);

int
main(void)
{
	char s[size + 4];
	if (!fgets(s, sizeof(s), stdin) || strcspn(s, "\n") != size)
		return 1;
	s[size] = 0;
	for (int i = 0; s[i]; ++i)
	if (s[i] < 'a' || s[i] > 'z')
		return 1;
	puts(next(s));
	puts(next(s));
	return 0;
}

const char *
next(char *s)
{
	for (;;) {
		int i;
		half_next(s);
		char c1 = s[0], c2 = s[1], c3;
		for (i = 1; (c3 = s[++i]); c1 = c2, c2 = c3)
			if (c1 + 1 == c2 && c2 + 1 == c3)
				break;
		if (!c3) {
			s[i - 1] = 'z';
			continue;
		}
		for (int i = 0; s[i]; ++i)
		if (s[i] == s[i + 1])
		for (int j = i + 2; s[j]; ++j)
		if (s[j] == s[j + 1])
			return s;
	}
}

void
half_next(char *s)
{
	int n = 0;
	for (; s[n]; ++n)
	switch (s[n]) {
	case 'i': case 'o': case 'l':
		++s[n];
		while (s[++n])
			s[n] = 'a';
		return;
	}
	int i = n - 2;
	while (--i >= 0 && s[i] != s[i + 1]) ;
	if (i < 0)
		n -= 2;
	while (--n >= 0 && s[n] == 'z') ;
	if (n < 0)
		exit(1);
	switch (++s[n]) {
	case 'i': case 'o': case 'l':
		++s[n];
		break;
	}
	while (s[++n])
		s[n] = 'a';
}
