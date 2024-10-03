#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
typedef int par[2];
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }
par a[100], t, d[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int n;
int get_int()
{
	int r = 0, c = getchar(), s = 1;
	while (c != '-' && c < '0' || c > '9') c = getchar();
	while (c == '-') s *= -1, c = getchar();
	while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
	return s*r;
}

void burn()
{ // burns whats on the burner. returns the number of blocks that are left.
	int i, s;
	for (i = 1; i < n; i++) if (a[i][0] == t[0] && a[i][1] == t[1]) break;
	if (i == n) return;
	s = a[i][0], a[i][0] = a[n - 1][0], a[n - 1][0] = s;
	s = a[i][1], a[i][1] = a[n - 1][1], a[n - 1][1] = s;
	n--;
}

void move(int x, int y)
{ // moves xth block to (x + d.x, y + d.y).
	int i, z = a[x][0] + d[y][0], w = a[x][1] + d[y][1];
	for (i = 0; i < n; i++) if (z == a[i][0] && w == a[i][1]) break;
	if (i < n) move(i, y);
	a[x][0] = z, a[x][1] = w;
	if (x == 0) burn();
}

void left(int n) { while (n--) printf("left\n"), move(0, 0); }
void right(int n) { while (n--) printf("right\n"), move(0, 1); }
void up(int n) { while (n--) printf("up\n"), move(0, 2); }
void down(int n) { while (n--) printf("down\n"), move(0, 3); }

void go_above(int x, int y)
{
	if (a[0][0] == x) left(1);
	a[0][1] < y + 1 ? up(y + 1 - a[0][1]) : down(a[0][1] - y - 1);
	a[0][0] < x ? right(x - a[0][0]) : left(a[0][0] - x);
}

void go_below(int x, int y)
{
	if (a[0][0] == x) left(1);
	a[0][1] < y - 1 ? up(y - 1 - a[0][1]) : down(a[0][1] - y + 1);
	a[0][0] < x ? right(x - a[0][0]) : left(a[0][0] - x);
}

void go_right(int x, int y)
{
	if (a[0][1] == y) up(1);
	a[0][0] < x + 1 ? right(x + 1 - a[0][0]) : left(a[0][0] - x - 1);
	a[0][1] < y ? up(y - a[0][1]) : down(a[0][1] - y);
}

void go_left(int x, int y)
{
	if (a[0][1] == y) up(1);
	a[0][0] < x - 1 ? right(x - 1 - a[0][0]) : left(a[0][0] - x + 1);
	a[0][1] < y ? up(y - a[0][1]) : down(a[0][1] - y);
}

int main()
{
	int i;
	n = get_int() + 1;
	a[0][0] = get_int(), a[0][1] = get_int();
	t[0] = get_int(), t[1] = get_int();
	rep(i, n - 1) a[i + 1][0] = get_int(), a[i + 1][1] = get_int();
	while (n > 1)
	{
		if (a[1][1] == t[1]) go_below(a[1][0], a[1][1]), up(1);
		if (a[1][0] < t[0]) go_left(a[1][0], a[1][1]), right(t[0] - a[1][0]);
		else go_right(a[1][0], a[1][1]), left(a[1][0] - t[0]);
		if (a[1][1] < t[1]) go_below(a[1][0], a[1][1]), up(t[1] - a[1][1]);
		else go_above(a[1][0], a[1][1]), down(a[1][1] - t[1]);
	}
	return 0;
}
