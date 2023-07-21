#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct fort {
  ll h;
  string c;
  bool operator<(const fort& rhs) const { return h < rhs.h; }
};

void sub(vector<fort>& f, vector<ll> diff, ll rnd) {
  for (int i = 0; i < 3; ++i) f[i].h -= diff[i]*rnd;
}

void sim(vector<fort>& f) {
  map<string,string> left = {{"A","B"}, {"B","C"}, {"C","A"}};

  vector<ll> shots = {0, 0, 0};

  if (f[0].h < f[1].h || left[f[2].c] == f[1].c) ++shots[1];
  else ++shots[0];

  ++shots[2];

  if (f[2].h > f[1].h || left[f[0].c] == f[2].c) ++shots[2];
  else ++shots[1];

  sub(f, shots, 1);
}

fort solve(vector<fort>& f) {
  while (true) {
    sort(f.begin(), f.end());

    assert(f[0].h >= 0);

    ll d1 = f[1].h - f[0].h, d2 = f[2].h - f[1].h;

    if (d1 == 0 && d2 == 0) return {0, "Rubble!"};
    else if (f[1].h == 0) return f[2];
    else if (f[0].h == 0) sub(f, {0, f[1].h, f[1].h}, 1);
    else if (f[1].h <= 10) sim(f);
    else if ((d1 != 0 and d2 != 0) and ((1 <= d1 && d1 <= 3) || (1 <= d2 && d2 <= 3))) sim(f);
    else if (min(d1, d2) >= 1) sub(f, {0,1,2}, min(d1, d2));
    else if (d2 >= 3) sub(f, {1, 1, 4}, min(f[0].h-1, d2/3));
    else if (d1 >= 3) sub(f, {0, 3, 3}, d1/3);
    else if (d1 == 1 || d2 == 1) sub(f, {3, 3, 3}, f[0].h/3);
    else sim(f);
  }
}

int main() {
  ll A, B, C;
  cin >> A >> B >> C;

  vector<fort> f = {{A,"A"}, {B, "B"}, {C, "C"}};
  fort ans = solve(f);

  if (ans.h == 0) cout << ans.c << endl;
  else cout << ans.c << ' ' << ans.h << endl;

  return 0;
}
