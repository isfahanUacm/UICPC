#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const char *vals = "shdc23456789TJQKA";
int perm[4], dirs;

bool card_less(pii c1, pii c2) {
  return c1.first != c2.first ? perm[c1.first] < perm[c2.first] :
    (c1.second < c2.second ^ (dirs >> c1.first & 1));
}

int main(void) {
  int n, ans = 99, best[99];
  pii cards[99];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char buf[9];
    scanf("%s", buf);
    cards[i] = pii(find(vals, vals+4, buf[1])-vals,
		   find(vals, vals+17, buf[0])-vals);
  }
  for (int i = 0; i < 4; ++i) perm[i] = i;
  do
   for (dirs = 0; dirs < 16; ++dirs)
      for (int i = n-1; i >= 0; --i) {
	best[i] = 1;
	for (int j = i+1; j < n; ++j)
	  if (card_less(cards[i], cards[j]))
	    best[i] = max(best[i], best[j]+1);
	ans = min(ans, n-best[i]);
      }
  while (next_permutation(perm, perm+4));
  printf("%d\n", ans);
}
