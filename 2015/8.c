#include <stdio.h>
#include <string.h>

int
main(void)
{
	int result1 = 0, result2 = 0;
	char buf[1024];
	while (fgets(buf, sizeof(buf), stdin)) {
		buf[strcspn(buf, "\r\n")] = 0;
		result1 += 2;
		for (int i = 0; buf[i]; ++i)
		if (buf[i] == '\\') {
			++result1;
			if (buf[++i] == 'x')
				result1 += 2;
		}
		result2 += 2;
		for (int i = 0; buf[i]; ++i)
		switch (buf[i]) {
		case '\\': case '"':
			++result2;
			break;
		}
	}
	printf("%d\n%d\n", result1, result2);
	return 0;
}
