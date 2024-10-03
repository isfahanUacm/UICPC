#include <stdio.h>
#include <assert.h>
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

void tograph(int **g, int *gg, int *x, int *y, int n, int m)
{
	int i;
	rep(i, n) gg[i] = 1;
	rep(i, m) gg[x[i]]++;
	rep(i, n - 1) gg[i + 1] += gg[i];
	rep(i, n) g[i] = gg + (i == 0 ? 0 : gg[i - 1]) + 1;
	rep(i, n) g[i][-1] = 0;
	rep(i, m) g[x[i]][g[x[i]][-1]++] = y[i];
}

void bfs(int **g, int n, int m, int *s, int *d, int e)
{
	int i, q[n], qe = 0, qs = 0;
	rep(i, n) d[i] = -1;
	rep(i, m) q[qe++] = s[i], d[s[i]] = 0;
	while (qs < qe)
	{
		int u = q[qs++];
		if (e && d[u]) printf("%d ", u + 1);
		rep(i, g[u][-1]) if (d[g[u][i]] == -1) d[g[u][i]] = d[u] + 1, q[qe++] = g[u][i];
	}
}

int longest_path(int **g, int n, int *r, int *t)
{
	int i, e[1], d[n], s = 0, k = 0;
	e[0] = 0; bfs(g, n, 1, e, d, 0);
	rep(i, n) if (d[i] > d[s]) s = i;
	e[0] = s; bfs(g, n, 1, e, d, 0);
	rep(i, n) if (d[i] > d[s]) s = i;
	while (1)
	{
		r[k++] = s;
		if (!d[s]) break;
		rep(i, g[s][-1]) if (d[s] == d[g[s][i]] + 1) break;
		assert(i < g[s][-1]);
		s = g[s][i];
	}
	return k;
}

int main()
{
	int i, j, n = get_int(), m = 2*(n - 1), gg[m + n], *g[n], x[m], y[m], d[n], k = 0, mx1 = 0, mx2;
	rep(i, n - 1)
	{
		int u = get_int() - 1, v = get_int() - 1;
		x[i] = y[i + m/2] = u;
		y[i] = x[i + m/2] = v;
	}
	tograph(g, gg, x, y, n, m);
	m = longest_path(g, n, x, y);
	if (m < 4) { printf("NO\n"); return 0; }
	printf("YES\n");
	if (m%2) printf("%d ", x[m/2] + 1);
	per(i, m/2) printf("%d ", x[i] + 1);
	rep(i, m/2) printf("%d ", x[(m + 1)/2 + i] + 1);
	bfs(g, n, m, x, d, 1);
	printf("\n");
	return 0;
}
