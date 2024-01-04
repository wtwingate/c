/*
 * K&R Exercise 3-3
 * Write a function `expand(s1, s2)` that expands shorthand notations
 * like `a-z` in the string `s1` into the equivalent complete list
 * `abc...xyz` in `s2`. Allow for letters of either case and digits,
 * and be prepared to handle cases like `a-b-c` and `a-z0-9` and
 * `-a-z`. Arrange that a leading or trailing `-` is taken literally.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int get_line(char str[], int lim);
void expand(char s1[], char s2[]);

int main(void)
{
	int length;
	char from[MAXLINE];
	char to[MAXLINE];

	while ((length = get_line(from, MAXLINE)) > 0) {
		expand(from, to);
		printf("%s", to);
	}

	return 0;
}

int get_line(char str[], int lim)
{
	int i, c;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
		str[i] = c;
	if (c == '\n')
		str[i++] = c;
	str[i] = '\0';
	return i;
}

void expand(char s1[], char s2[])
{
	int i, j, k;
	int left;
	int right;

	for (i = j = 0; s1[i] != '\0'; i++) {
		if (s1[i] == '-') {
			left = s1[i - 1];
			right = s1[i + 1];
			if (isdigit(left) && isdigit(right)
			|| isupper(left) && isupper(right)
			|| islower(left) && islower(right)) {
				left += 1;
				if (left < right) {
					for (k = left; k < right; k++) {
						s2[j++] = k;
					}
				} else {
					for (k = left; k > right; k--) {
						s2[j++] = k;
					}
				}
			} else {
				s2[j++] = s1[i];
			}
		} else {
			s2[j++] = s1[i];
		}
	}
	s2[j] = s1[i];
}
