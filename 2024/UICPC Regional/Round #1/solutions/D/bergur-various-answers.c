// prints the same answers as bergur.c but flips and rotates them.
// This tests the validator a bit.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int x, y = 1, s;
	scanf("%d", &x);
	x *= (2*(rand()%2) - 1);
	y *= (2*(rand()%2) - 1);
	if (rand()%2) s = x, x = y, y = s;
	printf("%d %d\n", x, y);
	return 0;
}
