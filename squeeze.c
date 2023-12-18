/*
 * K&R Exercise 2-4
 * Write an alternate version of `squeeze(s1,s2)` that deletes each character
 * in s1 that matches any character in the string s2.
 */

#include <stdio.h>
#include <string.h>

enum bool {TRUE, FALSE};

void squeeze(char s1[], char s2[]);

int main(void)
{
	char string[] = "The quick brown fox jumps over the lazy dog";
	char remove[] = "AEIOUaeiou";

	squeeze(string, remove);
	printf("%s\n", string);

	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	int match;
	char tmp[strlen(s1)];

	k = 0;
	for (i = 0; s1[i] != '\0'; i++) {
		match = FALSE;
		for (j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j]) {
				match = TRUE;
			}
		}
		if (match == FALSE) {
			tmp[k++] = s1[i];
		}
	}
	tmp[k] = '\0';

	for (i = 0; (s1[i] = tmp[i]) != '\0'; i++) {
		;
	}
}
