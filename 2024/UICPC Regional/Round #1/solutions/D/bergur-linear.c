#include <stdio.h>
typedef long long ll;
ll get_int()
{
	ll r = 0, c = getchar(), s = 1;
	while (c != '-' && c < '0' || c > '9') c = getchar();
	while (c == '-') s *= -1, c = getchar();
	while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
	return s*r;
}

int main()
{
	ll r = get_int(), x = 1000000000, y = 1000000000, i, j;
	for (i = r + 1, j = 0; j <= r; j++)
	{
		while ((i - 1)*(i - 1) + j*j > r*r) i--;
		if (i*i + j*j < x*x + y*y || i*i + j*j == x*x + y*y && i + j > x + y) x = i, y = j;
	}
	for (i = r + 1, j = 0; j <= r; j++)
	{
		while ((i - 1)*(i - 1) + j*j > r*r) i--;
		if (i*i + j*j == x*x + y*y) fprintf(stderr, ">> %d %d\n", i, j);
	}
	printf("%d %d\n", x, y);
	return 0;
}
