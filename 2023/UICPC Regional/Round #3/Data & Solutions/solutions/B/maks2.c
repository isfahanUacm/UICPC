/* Same solution as maks.c, but using different I/O functions.

   @EXPECTED_RESULTS@: CORRECT
*/

#include <stdio.h>
#include <stdlib.h>

static const char *get_line()
{
    static char buf[100];
    fflush(stdout);
    return fgets(buf, sizeof(buf), stdin) ? buf : "";
}

int main()
{
    int r1, c1, r2, c2, cases = atoi(get_line());
    while (cases-- > 0)
    {
        puts("5 1 5 6");
        while (sscanf(get_line(), "MOVE %d %d %d %d\n", &r1, &c1, &r2, &c2) == 4)
        {
            if (r1 > 4) r1 = 4;
            if (r2 > 4) r2 = 4;
            printf("%d %d %d %d\n", 5-r2, 7-c2, 5-r1, 7-c1);
        }
    }
    return 0;
}
