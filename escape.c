/*
 * K&R Exercise 3-2
 * Write a function `escape(s, t)` that converts characters like newline and
 * tab into visible escape sequences like \n and \t as it copies the string
 * `t` to `s`. Use a `switch`. Write a function for the other direction as
 * well, converting escape sequences into the real characters.
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char str[], int lim);
void escape(char s[], char t[]);
void un_escape(char s[], char t[]);

int main(void)
{
	int length;
	char from[MAXLINE];
	char to[MAXLINE];

	while ((length = get_line(from, MAXLINE)) > 0) {
		escape(to, from);
		printf("%s\n", to);
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

void escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; i++) {
		switch (t[i]) {
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
		}
	}
	s[j] = t[i];
}

void un_escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; i++) {
		if (t[i] == '\\') {
			i++;
			switch (t[i]) {
				case 'n':
					s[j++] = '\n';
					break;
				case 't':
					s[j++] = '\t';
					break;
				default:
					s[j++] = '\\';
					s[j++] = t[i];
			}
		} else {
			s[j++] = t[i];
		}
		s[j] = t[i];
	}
}
