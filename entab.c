/*
 * K&R Exercise 1-21
 * Write a program `entab` that replaces strings of blanks by the minimum
 * number of tabs and blanks to achieve the same spacing. Use the same tab
 * stops as for `detab`. When either a tab or a single blank would suffice
 * to reach a tab stop, which should be given preference?
 */

#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 8

int get_line(char s[], int max);
void entab(char to[], char from[]);

int main(void)
{
	int length;
	char line[MAXLINE];
	char entab_line[MAXLINE];

	while ((length = get_line(line, MAXLINE)) > 0) {
		entab(entab_line, line);
		printf("%s", entab_line);
	}
	return 0;
}

int get_line(char s[], int max)
{
	int i, c;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';

	return i;
}

void entab(char to[], char from[])
{
	int i, j;
	int column;
	int spaces;

	column = spaces = 0;
	for (i = j = 0; from[i] != '\0'; i++) {
		column++;
		if (from[i] == ' ') {
			spaces++;
			if ((column % TABSTOP) == 0) {
				to[j++] = '\t';
				spaces = 0;
			}
		} else {
			while (spaces > 0) {
				to[j++] = ' ';
				spaces --;
			}
			to[j++] = from[i];
		}
	}
	to[j] = from[i];
}
