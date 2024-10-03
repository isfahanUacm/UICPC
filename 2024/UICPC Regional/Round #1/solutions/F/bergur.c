#include <stdio.h>
#include <string.h>
#define MAXN 2000001
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

int get_string(char* b)
{
	int i = 0;
	b[i++] = getchar();
	while (b[i - 1] != ' ' && b[i - 1] != 10) b[i++] = getchar();
	b[i - 1] = '\0';
	return i - 1;
}

void prefix_function(char *p, int *b)
{
	int i, j, m = strlen(p);
	for (i = 0, j = b[0] = -1; i < m; b[++i] = ++j)
		while (j >= 0 && p[i] != p[j]) j = b[j];
}

int kmp(char *s, char *p, int *r)
{
	int i, j, n = strlen(s), m = strlen(p), b[m + 1], k = 0;
	prefix_function(p, b);
	rep(i, n) r[i] = 0;
	for (i = j = 0; i < n; )
	{
		while (j >= 0 && s[i] != p[j]) j = b[j];
		i++, j++;
		if (j == m)
		{
			if (i - j != 0) r[k++] = i - j;
			j = b[j];
		}
	}
	return k;
}

int check(char *x, char *y, char *z)
{
	if (strncmp(x, z, strlen(x))) return 0;
	z += strlen(x);
	if (strcmp(y, z)) return 0;
	return 1;
}

int r[MAXN];
char s[MAXN], t[MAXN];
int main()
{
	int i, j, n = get_int();
	if (n == 2)
	{
		get_string(s);
		int k1 = get_string(s);
		rep(i, k1) s[i + k1] = s[i];
		s[k1*2 - 1] = '\0';
		int k2 = get_string(t);
		int z = kmp(s, t, r);
		if (z == 0) { printf("NONE\n"); return 0; }
		if (z > 1) { printf("MANY\n"); return 0; }
		printf("UNIQUE\n");
		printf("%s\n", t + k2 - r[0]);
		t[k2 - r[0]] = '\0';
		printf("%s\n", t);
		return 0;
	}
	else
	{
		int a[n][n], z = 0, g;
		char *f[n][n], *p = s, *o[n];
		rep(i, n) rep(j, n)
		{
			a[i][j] = get_string(p);
			f[i][j] = p;
			p += a[i][j] + 1;
		}
		rep(i, n) r[i] = -1;
		rep(i, n) rep(j, n) r[i] += a[i][j];
		rep(i, n) z += r[i];
		g = z/(2*(n - 1));
		p = t;
		rep(i, n)
		{
			int l = (r[i] - g)/(n - 2);
			memcpy(p, f[i][(i + 1)%n], l);
			o[i] = p;
			p += l + 1;
			p[-1] = '\0';
		}
		rep(i, n) if (strlen(o[i]) == 0) { printf("NONE\n"); return 0; }
		rep(i, n) rep(j, n) if (i != j && !check(o[i], o[j], f[i][j])) { printf("NONE\n"); return 0; }
		printf("UNIQUE\n");
		rep(i, n) printf("%s\n", o[i]);
	}
	return 0;
}
