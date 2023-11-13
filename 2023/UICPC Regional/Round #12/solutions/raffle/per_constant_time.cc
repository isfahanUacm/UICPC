#include <bits/stdc++.h>

int main(void) {
  int n, p;
  scanf("%d%d", &n, &p);
  int x = n++/(p-1);
  printf("%.11lf\n", x*p*exp(lgamma(n-p+x)-lgamma(n-p+1)-lgamma(n+x)+lgamma(n)));
}
