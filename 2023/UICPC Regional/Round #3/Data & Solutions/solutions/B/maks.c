/*  Approach: in the first move, black out the bottom row to turn the 5x6 grid
              into a 4x6 grid.  Now we can reply to every move our opponent
              makes by rotating theirs by 180 degrees.

    @EXPECTED_RESULTS@: CORRECT
*/

#include <stdio.h>

int main()
{
    int r1, c1, r2, c2, cases = 0;
    setlinebuf(stdout);
    scanf("%d", &cases);
    while (cases-- > 0)
    {
        printf("5 1 5 6\n");
        while (scanf("\nMOVE %d %d %d %d", &r1, &c1, &r2, &c2) == 4)
        {
            if (r1 > 4) r1 = 4;
            if (r2 > 4) r2 = 4;
            printf("%d %d %d %d\n", 5 - r2, 7 - c2, 5 - r1, 7 - c1);
        }
        scanf("GAME");
    }
    return 0;
}
