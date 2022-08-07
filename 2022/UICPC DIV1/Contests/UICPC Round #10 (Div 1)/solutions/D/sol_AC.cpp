#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
typedef long long int lld;
typedef pair<lld, lld> pii;
#define F first
#define S second

lld p[MAXN], x[MAXN];
vector<pii> events;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++)
    scanf("%lld", &p[i]);

  for (int i = 0; i < m; i++)
    scanf("%lld", &x[i]);
  x[m] = -4000000005LL;
  x[m + 1] = 4000000005LL;
  m += 2;
  sort(x, x + m);

  int xind = 0;
  for (int i = 0; i < n; i++) {
    lld cpos = i * 100LL;
    while (x[xind] < cpos)
      xind++;

    if (x[xind] == cpos)
      continue;

    lld l = max(x[xind - 1], (cpos - (x[xind] - cpos)));
    lld r = min(x[xind], (cpos + cpos - x[xind - 1]));

    if (l < r) {
      events.push_back(pii(l, p[i]));
      events.push_back(pii(r, -p[i]));
      //      printf("%lld %lld -> %lld\n", l, r, p[i]);
    }
  }

  sort(events.begin(), events.end());

  lld mx = 0;
  lld current = 0;
  for (int i = 0; i < int(events.size()); i++) {
    auto e = events[i];
    current += e.S;
    if (i + 1 < int(events.size()) && e.F == events[i + 1].F)
      continue;
    mx = max(mx, current);
  }

  printf("%lld\n", mx);
  
  return 0;
}
