/* Sample solution for the deliveringpizzas problem in NCPC2018 by Andreas Björklund */
#include <stdio.h>

#define MAXN (1000)
#define INF ((long long)1e18)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

long long dst[MAXN][MAXN];
int n, m, o;
int s[MAXN], v[MAXN], t[MAXN];

long long base[MAXN+1];

int dp(long long cut_off)
{
  int i, j, k;
  base[0] = 0;
  for (i = 0; i < o; i++) {
    base[i+1] = INF;
    long long time;
    long long runtime = dst[v[i]][0];
    long long worst = -s[i];
    int ok = 1;
    
    for (j = i; j >= 0; j--) {
      time = MAX(base[j], t[i]) + dst[0][v[j]];
      ok = (time + worst) <= cut_off;
      if (ok) {
        base[i+1] = MIN(base[i+1], time + runtime);      
      }
      if (j) {
        runtime += dst[v[j-1]][v[j]];
        worst = MAX(-s[j-1], dst[v[j-1]][v[j]] + worst);
      }
    }
    if (base[i+1] == INF) return 0;
  }
  return 1;
}

long long binsearch(long long lo, long long hi)
{
  if (lo == hi) return lo;
  long long mid = (lo + hi) /2;
  if (dp(mid))
    return binsearch(lo, mid);
  else 
    return binsearch(mid+1, hi);
}

int main()
{
  int i, j, k;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) 
      dst[i][j] = i == j ? 0 : INF;
      
  for (i = 0; i < m; i++) {
    int f, t, d;
    scanf("%d %d %d", &f, &t, &d);t--;f--;
    dst[t][f] = dst[f][t] = d;
  }
  
  for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) 
        dst[i][j] = MIN(dst[i][j], dst[i][k] + dst[k][j]);
  
  scanf("%d", &o);
  for (i = 0; i < o; i++) {
    scanf("%d %d %d", &s[i], &v[i], &t[i]);
    v[i]--;
  }
  long long range = 2;
  while (!dp(range)) range *= 2;
  printf("%lld\n", binsearch(0, range));
  
  return 0;
}
