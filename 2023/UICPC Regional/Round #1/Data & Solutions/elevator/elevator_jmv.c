//Author: Jon Marius Venstad
#include <stdio.h>

#define M 1000000

int main() {
	int c, i, j, f, s, g, u, d, D[M], Q[M];
	scanf ("%d%d%d%d%d", &f, &s, &g, &u, &d);
	for (i = 0; i < M; i++) 
		D[i] = -1;
	s--;
	g--;
	i = 0; 
	j = 1;
	D[s] = 0;
	Q[i] = s;
	while (i != j) {
		c = Q[i];
		i = (i + 1) % M;
		if (c == g) {
			printf("%d\n", D[c]);
			
			return 0;
		}
		if (c - d >= 0 && D[c - d] < 0) {
			D[c - d] = D[c] + 1;
			Q[j] = c - d;
			j = (j + 1) % M;
		}
		if (c + u < f && D[c + u] < 0) {
			D[c + u] = D[c] + 1;
			Q[j] = c + u;
			j = (j + 1) % M;
		}
	}
	printf("use the stairs\n");
	
	return 0;
}
