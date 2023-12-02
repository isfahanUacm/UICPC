/* Sample solution for the explosion problem in NCPC2018 by Andreas Björklund */
#include <stdio.h>
#include <stdlib.h>

#define MAXN (5)

int x,y,z;
int xs[MAXN], ys[MAXN];

#define MAXH (2451671)
#define MAXL (10)

struct thash {
  char xs[MAXN],ys[MAXN];
  double val;
};

struct thash htab[MAXH];
 
void inithash()
{
  int i;
  for (i = 0; i < MAXH; i++)
    htab[i].val = -1.0;
}

int hash()
{
  int i;
  int sum = 1;
  for (i = 0; i < x; i++)
    sum = (13 * sum + xs[i]) % MAXH;
  
  for (i = 0; i < y; i++)
    sum = (13 * sum + ys[i]) % MAXH;
  return sum;
}

int equal(int hs)
{
  int i;
  int ident = 1;
  for (i = 0; i < x && ident; i++)
    ident = htab[hs].xs[i] == xs[i];
  for (i = 0; i < y && ident; i++)
    ident = htab[hs].ys[i] == ys[i];
  return ident;
}

double fetch()
{
  int hs = hash();
  int cur = MAXL;
  while (htab[hs].val>-1.0 && !equal(hs) && cur) { hs++; if (hs == MAXH) hs = 0; cur--;}
  if (htab[hs].val>-1.0 && equal(hs))
    return htab[hs].val;
  else
    return -1.0;
}

void insert(double val)
{
  int hs = hash();
  int cur = MAXL;
  while (htab[hs].val != -1.0 && cur) { hs++; if (hs == MAXH) hs = 0; cur--;}
  if (htab[hs].val == -1.0) {
    int i;
    for (i = 0; i < x; i++)
      htab[hs].xs[i] = xs[i];
    for (i = 0; i < y; i++)
      htab[hs].ys[i] = ys[i];
    htab[hs].val = val;  
  } 
}
  
double explode(int cur, int sy)
{
  int i;
  int nx = 0, ny = 0; 
  double pr = fetch();
  if (pr >= 0.0) return pr;
  pr = 0.0;

  for (i = 0; i < x; i++) nx += (xs[i] != 0);
  for (i = 0; i < y; i++) ny += (ys[i] != 0);
  if (!cur) return ny ? 0.0 : 1.0;
  if (!ny) return 1.0;
  if (sy > cur) return 0.0;
  for (i = 0; i < x; i++) 
    if (xs[i] && (!i || xs[i-1] < xs[i])) {
      int j = i + 1;
      while (j < x && xs[j] == xs[i]) j++;
      xs[i]--;
      pr += (j - i) * explode(cur - 1, sy) / (nx + ny);
      xs[i]++;
    }
  for (i = 0; i < y; i++) 
    if (ys[i] && (!i || ys[i-1] < ys[i])) {
      int j = i + 1;
      while (j < y && ys[j] == ys[i]) j++;
      ys[i]--;
      pr += (j - i) * explode(cur - 1, sy - 1) / (nx + ny);
      ys[i]++;
    }
  insert(pr);
  return pr;  
}

int cmp(const void* a, const void* b)
{
  return *((int*)a)-*((int*)b);
}

int main()
{
  int i, sy = 0;
  inithash();
  scanf("%d %d %d",&x,&y,&z);
  for (i = 0; i < x; i++) scanf("%d",&xs[i]); 
  qsort(xs, x, sizeof(int), cmp);
  for (i = 0; i < y; i++) { scanf("%d",&ys[i]); sy += ys[i];}
  qsort(ys, y, sizeof(int), cmp);
  printf("%1.8lf\n", explode(z, sy));
  return 0;
}
