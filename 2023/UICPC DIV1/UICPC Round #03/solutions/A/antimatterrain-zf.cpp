#include <bits/stdc++.h>

using namespace std;

#define L 19
#define MAXN (1<<L)
#define INF (1<<30)

struct object {
  int i, x1, x2, y; // x2 == -INF indicates a point
  bool operator<(const object& rhs) const { return y < rhs.y; }
};

const object NONE = {-1, 0, 0, INF};

// x_to_i compresses the distinct x-values in the input
unordered_map<int, int> x_to_i;

// for x-value represented by compressed index i, st[i] is the stack of points
// with this x-value that have been swept over but not yet destroyed
stack<object> st[MAXN];

// rmq: given a range [lo, hi), will return the point with minimum y-value
// in the range among all points we have swept over but not yet destroyed
object rmq[2*MAXN];

// records the y-value when point i dies.
vector<int> die;

// update the object with compressed x-position i to "obj"
void update(int i, object obj, int lq = 0, int hq = MAXN, int node = 0) {
  if (lq+1 == hq) {
    rmq[node] = obj;
    return;
  }

  int mid = (lq+hq)>>1, left = (node<<1)+1, right = (node<<1)+2;

  if (i < mid) update(i, obj, lq, mid, left);
  else update(i, obj, mid, hq, right);

  rmq[node] = min(rmq[left], rmq[right]);
}

// find an object with minimum y-coordinate spanned by the query range
object query(int lo, int hi, int lq = 0, int hq = MAXN, int node = 0) {
  if (hi <= lq || hq <= lo) return NONE;
  if (lo <= lq && hq <= hi) return rmq[node];

  int mid = (lq+hq)>>1;
  object obj_l = query(lo, hi, lq, mid, (node<<1)+1);
  object obj_r = query(lo, hi, mid, hq, (node<<1)+2);

  return min(obj_l, obj_r);
}

void addPoint(object obj) {
  int i = x_to_i[obj.x1];
  st[i].push(obj);
  update(i, obj);
}

void processBarrier(object obj) {
  int il = x_to_i[obj.x1], ih = x_to_i[obj.x2]+1;

  object orig = query(il, ih);
  if (orig.i == NONE.i) return;

  // continue killing off points as long as there is one in this range
  // with the same x-value as the first point to hit the wall
  for (object hit = orig; hit.y == orig.y; hit = query(il, ih)) {
    // record this point hit a wall
    die[hit.i] = obj.y;

    int i = x_to_i[hit.x1];
    assert(st[i].size() > 0 && st[i].top().i != -1);
    st[i].pop();

    // update the rmq data for the next point with y-coordinate i
    update(i, st[i].top());
  }

}

int main() {
  int n, m;
  cin >> n >> m;

  vector<object> obj(n+m);
  die.assign(n, 0);

  for (int i = 0; i < n; ++i) {
    cin >> obj[i].x1 >> obj[i].y;
    obj[i].i = i;
    obj[i].x2 = -INF;
  }

  for (int i = n; i < m+n; ++i) cin >> obj[i].x1 >> obj[i].x2 >> obj[i].y;

  sort(obj.begin(), obj.end());

  // determine the distinct x-values (compression)
  set<int> xvals;
  for (auto o : obj) {
    xvals.insert(o.x1);
    if (o.x2 != -INF) xvals.insert(o.x2);
  }
  for (int x : xvals) x_to_i[x] = x_to_i.size();
  assert(xvals.size() <= MAXN);

  // initialize RMQ and stack
  fill(rmq, rmq+2*MAXN, NONE);
  for (auto& s : st) s.push(NONE);

  // finally do the sweep
  for (int i = obj.size()-1; i >= 0; --i) {
    if (obj[i].x2 == -INF) addPoint(obj[i]);
    else processBarrier(obj[i]);
  }

  for (int y : die) cout << y << endl;

  return 0;
}
