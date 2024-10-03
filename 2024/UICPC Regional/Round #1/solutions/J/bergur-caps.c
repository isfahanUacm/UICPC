#include <stdio.h>
#define BIG 31
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }
int get_int()
{
	int r = 0, c = getchar(), s = 1;
	while (c != '-' && c < '0' || c > '9') c = getchar();
	while (c == '-') s *= -1, c = getchar();
	while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
	return s*r;
}

int x, y, a, b;

void left() { printf("LEFT\n"); x--; }
void right() { printf("RIGHT\n"); x++; }
void up() { printf("UP\n"); y++; }
void down() { printf("DOWN\n"); y--; }

int main()
{
	int i, j, n = get_int();
	x = get_int() , y = get_int(), a = get_int(), b = get_int();
	fprintf(stderr, ">> step 1\n");
	while (x >= 0) left(); // go out of bounds.
	down();
	rep(i, BIG) left(); // go further than everything you pushed out of bounds with you.
	up();
	rep(i, BIG) right(); // push everything back in bounds.
	fprintf(stderr, ">> step 2\n");
	while (y != 0) down();
	rep(i, BIG)
	{
		rep(j, i*BIG) right();
		rep(j, i*BIG) left();
		up();
	}
	fprintf(stderr, ">> step 3\n");
	// now there should be at most one block per column
	fprintf(stderr, ">> step 4\n");
	while (y != -1) down();
	while (x != 0) right();
	fprintf(stderr, ">> step 5\n");
	while (x < BIG*BIG)
	{ // now we push all the blocks to the same row as the burner.
		while (y != b - 1) up();
		while (y != -1) down();
		right();
	}
	fprintf(stderr, ">> step 6\n");
	while (y < BIG) up();
	while (x > -1)
	{ // now we push all the blocks to the same row as the burner.
		while (y != b + 1) down();
		while (y != BIG) up();
		left();
	}
	fprintf(stderr, ">> step 7\n");
	// now we push it all in.
	while (y != b) down();
	while (x != a - 1) right();
	fprintf(stderr, ">> step 8\n");
	down();
	fprintf(stderr, ">> step 9\n");
	while (x != BIG*BIG) right();
	up();
	fprintf(stderr, ">> step 10\n");
	while (x != a + 1) left();
	return 0;
}
