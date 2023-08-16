//Author: Jon Marius Venstad

#include <stdio.h>

#define N 1001

void dfs(int s, int G[N][N], int v[N]) {
	int i;
	v[s] = 1;
	for (i = 0; i < N; i++) 
		if (G[s][i] && !v[i]) dfs(i, G, v);
}

void rdfs(int s, int G[N][N], int r[N]) {
	int i;
	r[s] = 1;
	for (i = 0; i < N; i++) 
		if (G[i][s] && !r[i]) rdfs(i, G, r);
}

int main() {
	int i, j, n, s, t, u, G[N][N], v[N], r[N], p[N];
	scanf("%d", &n);
	for (i = 0; i < N; i++) {
		v[i] = 0;
		r[i] = 0;
		for (j = 0; j < N; j++) 
			G[i][j] = 0;
	}
	for (i = 0; i < n; i++) {
		scanf("%d%d", &s, &t);
		p[i] = s;
		for (j = 0; j < t; j++) {
			scanf("%d", &u);
			G[s][u] = 1;
		}
	}
	
	v[0] = r[0] = 1;
	dfs(0, G, v);
	rdfs(0, G, r);
	
	int ok = 1;
	for (i = 0; i < n; i++) {
		if (!r[p[i]]) {
			printf("TRAPPED %d\n", p[i]);
			ok = 0;
		}
	}
	for (i = 0; i < n; i++) {
		if (!v[p[i]]) {
			printf("UNREACHABLE %d\n", p[i]);
			ok = 0;
		}
	}
	if (ok) printf("NO PROBLEMS\n");
	
	return 0;
}
