#include <bits/stdc++.h>
using namespace std;
const int oo = 1<<25;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct crossing {
  int c;
  vpii ivals[2][2];

  crossing(int c): c(c) {}

  void add(pii ival) {
    ivals[ival.first >= c][ival.second >= c].push_back(pii(abs(ival.first - c),
							   abs(ival.second - c)));
  }

  void init() {
    for (int a = 0; a < 2; ++a)
      for (int b = 0; b < 2; ++b) {
	vpii &I = ivals[a][b];
	if (!I.empty()) {
	  sort(I.begin(), I.end());
	  int at = 0;
	  for (int i = 1; i < I.size(); ++i)
	    if (I[i].second < I[at].second) I[++at] = I[i];	
	  I.resize(at+1);
	}
      }
  }

  pii get_bounds(int tl, int tr) const {
    int tx[2] = {c-tl, tr-c}, bx[2] = {oo, oo};
    for (int a = 0; a < 2; ++a)
      for (int b = 0; b < 2; ++b) {
	auto it = lower_bound(ivals[a][b].begin(), ivals[a][b].end(), pii(tx[a], a ? oo : -oo));
	if (it != ivals[a][b].begin())
	  bx[b] = min(bx[b], (--it)->second);
      }
    return pii(c-bx[0], c+bx[1]);
  }

  void flip() {
    swap(ivals[0][1], ivals[1][0]);
    for (int a = 0; a < 2; ++a)
      for (int b = 0; b < 2; ++b) {
	for (auto &I: ivals[a][b]) swap(I.first, I.second);
	reverse(ivals[a][b].begin(), ivals[a][b].end());
      }
  }
};

struct side {
  int c1, c2, n;
  vpii ivals;
  // nextL[x]: permissible pos for last item in opt on [0..x] 
  // nextR[x]: permissible pos for first item in opt on [x..n]
  // g_nextR[x]: permissible pos for next item in global opt, restricted to pos [x..n]
  vpii nextL, nextR, g_nextR;
  // optL[x]: opt cost for [0..x]
  // optR[x]: opt cost for [x..n]
  // c2L[x]: max y < c2.c s.t. there is opt on [x..n] using y but none using y+1, or x-1 if none
  // g_optR[x]: min y >= x s.t. exist global opt using y
  vector<int> optL, optR, c2L;

  side(int c1, int c2, int n): c1(c1), c2(c2), n(n) {}

  void init() {
    int at, next;

    optL.resize(n+2);
    nextL.resize(n+2);
    optR.resize(n+2);
    nextR.resize(n+2);
    c2L.resize(n+2);
    g_nextR.resize(n+2);

    sort(ivals.begin(), ivals.end(), [](pii a, pii b) { return a.second < b.second; });
    at = 0;
    next = 0;
    optL[0] = 0;
    for (int i = 1; i <= n+1; ++i) {
      while (at < ivals.size() && ivals[at].second <= i) {
	next = max(next, ivals[at].first);
	++at;
      }
      optL[i] = next > 0 ? 1 + optL[next] : 0;
      nextL[i].first = next;
      nextL[i].second = nextL[i-1].second;
      while (optL[nextL[i].second+1] < optL[i]) ++nextL[i].second;
    }

    sort(ivals.begin(), ivals.end(), [](pii a, pii b) { return a.first > b.first; });
    at = 0;
    next = n+1;
    optR[n+1] = 0;
    nextR[n+1] = pii(n, n);
    for (int i = n; i >= 0; --i) {
      while (at < ivals.size() && ivals[at].first >= i) {
	next = min(next, ivals[at].second);
	++at;
      }
      optR[i] = next < n+1 ? 1 + optR[next] : 0;
      nextR[i].second = next-1;
      nextR[i].first = nextR[i+1].first;
      while (optR[nextR[i].first] < optR[i]) --nextR[i].first;
    }

    for (int i = c2; i >= 0; --i) {
      int nf = nextR[i].second;
      if (nf >= c2) c2L[i] = i-1;
      else c2L[i] = max(nf, c2L[nf+1]);;
    }
    
    g_nextR[n] = g_nextR[n+1] = pii(n, n);
    for (int i = n-1; i >= 0; --i) {
      g_nextR[i] = g_nextR[i+1];
      if (optL[i] + optR[i+1] + 1 == optR[0]) {
	if (g_nextR[i].first != i+1 || optL[i+1] > optL[i])
	  g_nextR[i].second = i;
	g_nextR[i].first = i;
      }
    }
    /*
    for (int i = 0; i <= n+1; ++i) {
      printf("i %d: L next %d %d opt %d, R next %d %d opt %d, c2L %d g_optR %d %d\n",
	     i,
	     nextL[i].first, nextL[i].second, optL[i],
	     nextR[i].first, nextR[i].second, optR[i],
	     c2L[i], g_nextR[i].first, g_nextR[i].second);
    }
    */
  }
};


vpii get_side_cross_cands(const side &s, const crossing &c) {
  vpii res;
  int R = s.g_nextR[c.c].first;
  res.push_back(pii(s.nextL[R].second, R));
  if (R == c.c && s.g_nextR[c.c-1].first == c.c-1) {
    res.push_back(pii(c.c-1, s.nextR[c.c].first));
  }
  return res;
}


vector<pii> opt;

void add_edge(int l, bool cross = false) {
  opt.push_back(pii(l, l + 1 + !cross));
}

void add_L_opt(int L, const side &s, bool odd) {
  while (L > 0) {
    add_edge(2*L-odd);
    L = s.nextL[L].second;
  }
}

void add_R_opt(int R, const side &s, bool odd) {
  while (R < s.n) {
    add_edge(2*R-odd);
    R = s.nextR[R+1].first;
  }
}

void add_M_opt(int L, int R, const side &s, bool odd) {
  while (L < R) {
    add_edge(2*L-odd);
    L = s.nextR[L+1].second;
  }
  add_edge(2*R-odd);
}

void solve0(const side &s1, const side &s2) {
  opt.clear();
  add_edge(2*s1.c1-1, true);
  add_edge(2*s1.c2-1, true);
  add_R_opt(s1.nextR[0].first, s1, true);
  add_R_opt(s2.nextR[0].first, s2, false);
}

void solve1(const side &s1, const side &s2, const crossing &c) {
  for (auto TP: get_side_cross_cands(s1, c)) {
    pii req = c.get_bounds(TP.first, TP.second);
    for (auto BP: get_side_cross_cands(s2, c)) {
      if (BP.first >= req.first && BP.second < req.second) {
	opt.clear();
	add_edge(2*(s1.c1+s1.c2-c.c)-1, true);
	add_L_opt(TP.first, s1, true);
	add_R_opt(TP.second, s1, true);
	add_L_opt(BP.first, s2, false);
	add_R_opt(BP.second, s2, false);
	return;
      }
    }
  }
}


bool solve2B(const side &s2, const crossing &c1, const crossing &c2,
	     int TL1, int TR1, int TL2, int TR2, int to_beat, bool side_swap) {
  pii c1B = c1.get_bounds(TL1, TR1);
  pii c2B = c2.get_bounds(TL2, TR2);

  //  printf("go %d %d %d %d to_beat %d, bounds (%d,%d), (%d,%d)\n", TL1, TR1, TL2, TR2, to_beat, c1B.first, c1B.second, c2B.first, c2B.second);
  
  if (c1B.first == c1.c || c1B.second == c1.c ||
      c2B.first == c2.c || c2B.second == c2.c)
    return false;

  vector<int> BR1cands;
  BR1cands.push_back(c1.c);
  BR1cands.push_back(c2.c-1);
  BR1cands.push_back(max(c2B.first, 0));
  BR1cands.push_back(min(c1B.second-1, s2.n));
  BR1cands.push_back(min(c2B.second-1, s2.n));
  BR1cands.push_back(s2.g_nextR[c1.c].second);
  if (s2.g_nextR[c1.c].second < s2.n) {
    BR1cands.push_back(s2.g_nextR[s2.g_nextR[c1.c].second+1].second);
  }
  BR1cands.push_back(s2.nextR[c1.c].second);

  bool improved = false;
  for (int BR1: BR1cands) {
    //    printf(" BR1cand %d\n", BR1);
    if (BR1 < c1.c || BR1 >= c1B.second) continue;
    if (s2.nextL[BR1].first >= c1.c) continue;

    vector<int> BL1cands;
    BL1cands.push_back(min(s2.nextL[BR1].second, c1.c-1));
    BL1cands.push_back(c1.c-1);
    
    for (int BL1: BL1cands) {
      //      printf("  BL1cand: %d\n", BL1);
      if (BL1 < c1B.first) continue;

      vector<int> BL2cands;
      if (BR1 < c2.c) {
	BL2cands.push_back(c2B.first);
	BL2cands.push_back(s2.c2L[BR1+1]);
	BL2cands.push_back(c2.c-1);
      } else {
	BL2cands.push_back(BL1);
      }

      for (int BL2: BL2cands) {
	if (BL2 < c2B.first) continue;
	if (BR1 < c2.c && BL2 < BR1) continue;
	if (BL2 < BL1) continue;
	if (s2.nextR[BL2+1].second < c2.c) continue;
	vector<int> BR2cands;
	BR2cands.push_back(max(s2.nextR[BL2+1].first, c2.c));
	BR2cands.push_back(c2.c);
	BR2cands.push_back(BR1);

	for (int BR2: BR2cands) {
	  if (BR2 >= c2B.second) continue;
	  if (BR2 < BR1 || BR2 < c2.c) continue;
	  int L_cost = s2.optL[BL1] + (BL1 > 0);
	  int M_cost = (BR1 < s2.n);
	  if (BR1 <= BL2) {
	    int y = s2.c2L[BR1+1];
	    M_cost += s2.optR[BR1+1] - s2.optR[y+1];
	    if (y < BL2) ++M_cost;
	  }
	  int R_cost = (BR1 < BR2 && BR2 < s2.n) + s2.optR[BR2+1];
	  
	  int cost = L_cost + M_cost + R_cost;
	  //	  printf("    try BL1 %d BR1 %d BL2 %d BR2 %d cost %d = %d+%d+%d\n", BL1, BR1, BL2, BR2, cost, L_cost, M_cost, R_cost);
	  if (cost < to_beat) {
	    opt.clear();
	    add_L_opt(BL1, s2, side_swap);
	    //	    assert(opt.size() == L_cost);
	    if (BR1 < s2.n) {
	      add_M_opt(BR1, max(BL2, BR1), s2, side_swap);
	      //	      assert(opt.size() == L_cost + M_cost);
	      if (BR1 == BR2) opt.pop_back();
	    }
	    add_R_opt(BR2, s2, side_swap);
	    //	    assert(opt.size() == cost);
	    to_beat = cost;
	    improved = true;
	  }
	}
      }
    }
  }
  return improved;
}


void solve2(const side &s1, const side &s2, const crossing &c1, const crossing &c2, bool side_swap) {
  for (int TL1 = c1.c-1; TL1 >= 0; --TL1) {
    if (s1.nextR[TL1+1].second < c2.c) break;
    int TR1 = max(c2.c, s1.nextR[TL1+1].first);
    int cost = s1.optL[TL1] + (TL1 > 0) + (TR1 < s1.n) + s1.optR[TR1+1];
    if (solve2B(s2, c1, c2, TL1, TR1, TL1, TR1, opt.size() - cost, side_swap)) {
      add_L_opt(TL1, s1, !side_swap);
      add_R_opt(TR1, s1, !side_swap);
    }
  }

  for (int TR1 = c1.c; TR1 < c2.c; ++TR1) {
    if (s1.optL[TR1] + 1 + s1.optR[TR1+1] > s1.optR[0]) continue;
    
    if (s1.nextL[TR1].first >= c1.c) break;
    int TL1 = min(c1.c-1, s1.nextL[TR1].second);

    vector<int> TL2cands;
    TL2cands.push_back(s1.c2L[TR1+1]);
    if (s1.nextR[s1.c2L[TR1+1]+1].first < c2.c) {
      TL2cands.push_back(c2.c-1);
    }
    
    for (int TL2: TL2cands) {
      int TR2 = max(s1.nextR[TL2+1].first, c2.c);
      if (solve2B(s2, c1, c2, TL1, TR1, TL2, TR2, opt.size() - s1.optR[0], side_swap)) {
	add_L_opt(TL1, s1, !side_swap);
	add_M_opt(TR1, TL2, s1, !side_swap);
	add_R_opt(TR2, s1, !side_swap);
      }
    }
  }
}


int main(void) {
  int n, m, c1, c2;
  assert(scanf("%d%d%d%d", &n, &m, &c1, &c2) == 4);
  ++c1; ++c2;
  if (c1 > c2) swap(c1, c2);
  side sides[2] = {side(c1/2, c2/2, n/2), side(c1/2, c2/2, n/2)};
  crossing crossings[2] = {crossing(c1/2), crossing(c2/2)};
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    assert(scanf("%d%d", &a, &b) == 2);
    ++a; ++b;
    if ((a+b) % 2) {
      if (a % 2) swap(a, b);
      assert(scanf("%d", &c) == 1);
      crossings[c+1==c2].add(pii(a/2, b/2));
    } else {
      if (a > b) swap(a, b);
      sides[a%2].ivals.push_back(pii(a/2, b/2));
    }
  }
  sides[0].init();
  sides[1].init();
  crossings[0].init();
  crossings[1].init();

  solve0(sides[0], sides[1]);
  solve1(sides[0], sides[1], crossings[0]);
  solve1(sides[0], sides[1], crossings[1]);
  solve2(sides[0], sides[1], crossings[0], crossings[1], false);
  crossings[0].flip();
  crossings[1].flip();
  solve2(sides[1], sides[0], crossings[0], crossings[1], true);
  printf("%zd\n", opt.size());
  for (pii p: opt)
    printf("%d %d\n", p.first, p.second);
}
