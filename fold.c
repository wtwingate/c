/*
 * K&R Exercise 1-22
 * Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define MAXLINE   1000
#define LINEBREAK 80

enum bool {FALSE, TRUE};

int get_line(char s[], int lim);
void fold_line(char s[], int len);

int main(void)
{
	int length;
	char line[MAXLINE];

	while ((length = get_line(line, MAXLINE)) > 0) {
		fold_line(line, length);
	}
	return 0;
}

int get_line(char s[], int lim)
{
	int i, c;

	for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';

	return i;
}

void fold_line(char s[], int len)
{
	int i, j;
	int column;
	int start;
	int end;
	int is_blank;

	if (len <= LINEBREAK) {
		printf("%s", s);
		return;
	} 

	column = start = end = 0;
	is_blank = FALSE;
	for (i = 0; s[i] != '\0'; i++) {
		column++;
		if (s[i] == ' ' || s[i] == '\t') {
			if (is_blank == FALSE) {
				end = i;
				is_blank = TRUE;
			} else {
				is_blank = TRUE;
			}
		} else {
			is_blank = FALSE;
		}

		if (column == LINEBREAK - 1) {
			for (j = start; j < end; j++) {
				putchar(s[j]);
			}
			putchar('\n');
			column = 0;
			start = end + 1;
			i = start;
		}
	}
}
