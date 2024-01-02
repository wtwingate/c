/*
 * K&R Exercise 3-2
 * Write a function `escape(s, t)` that converts characters like newline and
 * tab into visible escape sequences like \n and \t as it copies the string
 * `t` to `s`. Use a `switch`. Write a function for the other direction as
 * well, converting escape sequences into the real characters.
 */

void escape(char s[], char t[]);
void un_escape(char s[], char t[]);

int main(void)
{
	return 0;
}

void escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] == '\0'; i++) {
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
}

void un_escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] == '\0'; i++) {
		if (t[i] == '\\') {

		} else {
			s[j++] = t[i];
		}
	}
}
