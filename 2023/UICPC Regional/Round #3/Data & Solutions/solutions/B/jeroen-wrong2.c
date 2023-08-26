/*
 * @EXPECTED_RESULTS@: RUN-ERROR
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
	char cmd[5];
	int t, r1, c1, r2, c2;
	scanf("%d", &t);
	while(t--) {
		printf("1 1 1 6\n");
		fflush(NULL);
		while(true) {
			scanf("%s",cmd);
			if(cmd[0] == 'M') {
				scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
				printf("%d %d %d %d\n", 7-r2, 7-c2, 7-r1, 7-c1); // this can lead to 6's for the rows!
				fflush(NULL);
			}
			else break;
		}
	}
	return 0;
}
