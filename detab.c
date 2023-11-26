/* 
 * K&R Exercise 1-20
 * Write a program `detab` that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a
 * fixed set of tab stops, say every n columns. Should n be a variable
 * or a symbolic parameter?
 */

#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 8

int get_line(char str[], int max);
void detab(char to[], char from[]);

int main(void)
{
	int length;
	char line[MAXLINE];
	char detab_line[MAXLINE];

	length = 0;
	while ((length = get_line(line, MAXLINE)) > 0) {
		detab(detab_line, line);
		printf("%s", detab_line);
	}
	return 0;
}

int get_line(char str[], int max)
{
	int c;
	int len;

	for (len=0; len<max-1 && (c=getchar())!= EOF && c!='\n'; len++) {
		str[len] = c;
	}
	if (c == '\n') {
		str[len] = '\n';
		len++;
	}
	str[len] = '\0';

	return len;
}

void detab(char to[], char from[])
{
	int i;
	int j;
	int column;
	int spaces;

	column = 1;
	i = j = 0;
	while (from[j] != '\0') {
		if (from[j] == '\t') {
			spaces = TABSTOP - (column % TABSTOP);
			while (spaces >= 0) {
				to[i] = ' ';
				column++;
				i++;
				spaces--;
			}
			j++;
		} else {
			to[i] = from[j];
			column++;
			i++;
			j++;
		}
	}
	to[i] = from[j];
}
