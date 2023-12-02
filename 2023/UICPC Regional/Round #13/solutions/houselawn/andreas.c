/* Sample solution for the lawnmower problem in NCPC2018 by Andreas Björklund */
#include <stdio.h>

#define MAXM (100)
#define MAXP (100001)

void readname(char* n)
{
  char c;
  int cnt = 0;
  scanf("%c",&c);
  while (c != ',') {
    n[cnt++] = c;
    scanf("%c",&c);
  }
  n[cnt] = 0;  
}

int main()
{
  int i, m, l;
  char name[MAXM][61];
  int p[MAXM];
  int c, t, r;
  int best = MAXP, cnt = 0;
  
  scanf("%d %d\n",&l, &m);
  for (i = 0; i < m; i++) {
    readname(name[i]);
    scanf("%d,%d,%d,%d\n", &p[i], &c, &t, &r);
    if (10080l*c*t < ((long long)(t+r))*l) {
      p[i] = MAXP;
    }
    if (p[i] < best) best = p[i];
  }
  if (best < MAXP) {
    for (i = 0; i < m; i++) 
      if (p[i] == best) printf("%s\n",name[i]);
  } else 
    printf("no such mower\n");
  return 0;
}
