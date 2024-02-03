#include <stdio.h>
#include <stdlib.h>

enum { stacksize = 512 };

int		 readstr(void);

int
main(void)
{
	int stack[stacksize], n = 0;
	int sum, num, red = 1;
	stack[n] = sum = 0;
	for (;;) {
		int ch = getchar();
		switch (ch) {
		case EOF:
			if (n != 0) return 1;
			printf("%d\n%d\n", sum, stack[n]);
			return 0;
		case '-': case '+':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			ungetc(ch, stdin);
			if (scanf("%d", &num) != 1)
				return 1;
			sum += num;
			stack[n] += num;
			break;
		case '"':
			(void)readstr();
			break;
		case ':':
			do ch = getchar();
			while (ch == ' ' || ch == '\n');
			if (ch != '"')
				ungetc(ch, stdin);
			else if (readstr() && n < red)
				red = n;
			break;
		case '{':
			if (++n == stacksize) return 1;
			stack[n] = 0;
			if (n == red) ++red;
			break;
		case '}':
			if (n < 1) return 1;
			if (n-- < red) stack[n] += stack[n + 1];
		case '[': case ']': case ',': case ' ': case '\n':
			break;
		default:
			return 1;
		}
	}
}

int
readstr(void)
{
	int state = 0;
	for (;;)
	switch (getchar()) {
	case EOF: exit(1);
	case 'r': state = state == 0 ? 1 : -1; break;
	case 'e': state = state == 1 ? 2 : -1; break;
	case 'd': state = state == 2 ? 3 : -1; break;
	case '"': return state == 3;
	case '\\':
		if (getchar() == EOF)
			exit(1);
	default:
		state = -1;
		break;
	}
}
