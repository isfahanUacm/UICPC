//Author: Hans Wennborg
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool match(const char *p, const char *s)
{
	ssize_t		i, j, p_len, s_len, x;
	bool		a[101][101];

	p_len = strlen(p);
	s_len = strlen(s);

	for (i = p_len; i >= 0; i--) {
		for (j = s_len; j >= 0; j--) {
			if (i == p_len && j == s_len) {
				/* Base case. */
				a[i][j] = true;
			} else if (p[i] == s[j]) {
				/* Characters match. */
				a[i][j] = a[i + 1][j + 1];
			} else if (p[i] == '*') {
				/* Wildcard. */
				a[i][j] = false;
				for (x = j; x <= s_len; x++) {
					if (a[i + 1][x]) {
						a[i][j] = true;
						break;
					}
				}
			} else {
				a[i][j] = false;
			}
		}
	}
	return a[0][0];
}

int main()
{
	char	p[101], s[101];
	int	n, i;

	scanf("%s", p);
	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf("%s", s);
		if (match(p, s)) {
			printf("%s\n", s);
		}
	}

	return 0;
}
