#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
typedef long long ll;

ll randint(ll x, ll y)
{
	return rand()%(y - x) + x;
}

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
	srand(time(NULL));
	ll r = get_int(), x = 1000000000, y = 1000000000, i, j, cc = 10000000;
	if (r == 1)
	{
		printf("1 1\n");
		return 0;
	}
	while (cc--)
	{
		i = randint(1, r), j = randint((ll)(1.0 + sqrt(r*r - i*i)), r + 1);
		assert(i*i + j*j > r*r);
		if (i*i + j*j < x*x + y*y) x = i, y = j;
	}
	printf("%d %d\n", x, y);
	return 0;
}
