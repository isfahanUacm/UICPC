#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, c1, c2;

int house_type(int a, bool include_ends = false) {
  if (a < c1 + 2*include_ends) return a % 2;
  if (a > c2+1 - 2*include_ends) return 2 + a % 2;
  return 4;
}

int cycle_trunc(int a) {
  if (a < c1) return c1 + 1 - a % 2;
  if (a > c2 + 1) return c2 + 1 - a % 2;
  return a;
}

struct call {
  int a, b, c;
};

void solve_cycle(vector<pii> &calls, vector<pii> &res) {
  int n = c2-c1+2;

  if (calls.empty()) return;
  
  for (auto &p: calls) {
    if (p.first % 2) p.first = (p.first-c1)/2;
    else p.first = n/2 + (c2+1-p.first)/2;
    if (p.second % 2) p.second = (p.second-c1)/2;
    else p.second = n/2 + (c2+1-p.second)/2;
    if (p.second < p.first) p.second += n;
  }
  sort(calls.begin(), calls.end(), greater<pii>());
  int opt[n], next[n], maxend[n], minend = 2*n;
  auto it = calls.begin();
  for (int i = n-1; i >= 0; --i) {
    for (; it != calls.end() && it->first >= i; ++it)
      minend = min(minend, it->second);
    next[i] = minend-1;
    opt[i] = minend < 2*n ? 1 + (minend < n ? opt[minend] : 0) : 0;
    maxend[i] = minend < 2*n ? minend < n ? maxend[minend] : minend-1 : -1;
  }
  assert(it == calls.end());
  
  if (minend >= n) { // all calls wrap around the c1 crossing
    res.push_back(pii(c1, c1+1));
    return;
  }
  
  int bi = -1, bv = n+1;
  for (int i = 0; i < minend; ++i) {
    assert(i+1 < n);
    int v = 1 + opt[i+1] - (maxend[i+1] >= n+i);
    if (v < bv) {
      bv = v;
      bi = i;
    }
  }
  
  for (int i = bi; i+1 < n; i = next[i+1])
    res.push_back(pii(i, i+1));
  if (maxend[bi+1] >= n-1 && maxend[bi+1] < n + bi)
    res.push_back(pii(maxend[bi+1] % n, (maxend[bi+1]+1) % n));
  for (auto &r: res) {
    r.first = r.first < n/2 ? c1 + 2*r.first : c2+1 - 2*(r.first-n/2);
    r.second = r.second < n/2 ? c1 + 2*r.second : c2+1 - 2*(r.second-n/2);
  }
}
  
int main(void) {
  int m;
  scanf("%d%d%d%d", &n, &m, &c1, &c2);
  vector<call> calls[5];
  
  for (int i = 0; i < m; ++i) {
    call C;
    scanf("%d%d", &C.a, &C.b);
    if (C.a > C.b) swap(C.a, C.b);
    if (C.a % 2 != C.b % 2)
      scanf("%d", &C.c);
    int t1 = house_type(C.a, true);
    int t2 = house_type(C.b, true);
    calls[t1 != t2 ? 4 : t1].push_back(C);
  }

  vector<pii> tails_sol, sol;
  int last[4];
  
  for (int type = 0; type < 2; ++type) {
    sort(calls[type].begin(), calls[type].end(), [type](call &X, call &Y) { return X.b < Y.b; });
    last[type] = -1;
    for (auto &C: calls[type]) {
      if (last[type] == -1 || last[type] <= C.a) {
	tails_sol.push_back(make_pair(C.b-2, C.b));
	last[type] = C.b;
      }
    }
  }
  
  for (int type = 2; type < 4; ++type) {
    sort(calls[type].begin(), calls[type].end(), [type](call &X, call &Y) { return X.a > Y.a; });
    last[type] = 2*n;
    for (auto &C: calls[type]) {
      if (last[type] == 2*n || last[type] >= C.b) {
	tails_sol.push_back(make_pair(C.a, C.a+2));
	last[type] = C.a;
      }
    }
  }

  vector<call> rem;
  for (auto C: calls[4]) {
    int t1 = house_type(C.a), t2 = house_type(C.b);
    if (t1 < 2 && last[t1] > C.a ||
	2 <= t1 && t1 < 4 && last[t1] < C.a ||
	t2 < 2 && last[t2] > C.b ||
	2 <= t2 && t2 < 4 && last[t2] < C.b) continue;
    rem.push_back(C);
  }

  for (int extras = 0; extras < 16; ++extras) {
    vector<pii> cycle, cycle_sol;
    for (auto C: rem) {
      int t1 = house_type(C.a);
      int t2 = house_type(C.b);
      if (extras & ((1<<t1) | (1<<t2))) continue;
      C.a = cycle_trunc(C.a);
      C.b = cycle_trunc(C.b);
      if (C.a == C.b) goto skip;
      if (C.a % 2 == C.b % 2) {
	if (C.a % 2 == 0) swap(C.a, C.b);
      } else {
	if (C.c == c2 ^ (C.a % 2)) swap(C.a, C.b);
      }
      cycle.push_back(make_pair(C.a, C.b));
    }
    solve_cycle(cycle, cycle_sol);
    if (extras & 1) cycle_sol.push_back(make_pair(c1+1, c1-1));
    if (extras & 2) cycle_sol.push_back(make_pair(c1, c1-2));
    if (extras & 4) cycle_sol.push_back(make_pair(c2+1, c2+3));
    if (extras & 8) cycle_sol.push_back(make_pair(c2, c2+2));
    if (sol.empty() ||
	cycle_sol.size() + tails_sol.size() < sol.size()) {
      sol = tails_sol;
      copy(cycle_sol.begin(), cycle_sol.end(), back_inserter(sol));
    }
  skip:;
  }
  printf("%d\n", sol.size());
  for (auto &P: sol)
    printf("%d %d\n", P.first, P.second);
}
