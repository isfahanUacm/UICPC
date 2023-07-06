#include <bits/stdc++.h>

using namespace std;

struct Point
{
  int index, x, y;

  void read(int ind)
  {
    cin >> x >> y;
    index = ind;
  }
};

struct pq_record
{
  int timestamp;        // iteration in which the record is pushed into pq
  int index;            // which point
  int area2;            // 2*area associated with triangle

  pq_record() { }
  pq_record(int t, int i, Point p1, Point p2, Point p3)
    : timestamp{t}, index{i}
  {
    int dx1 = p1.x - p2.x, dy1 = p1.y - p2.y;
    int dx2 = p3.x - p2.x, dy2 = p3.y - p2.y;

    area2 = abs(dx1 * dy2 - dx2 * dy1);
  }
  
  bool operator<(const pq_record &r) const
  {
    // reverse comparison for min pq
    if (area2 != r.area2) {
      return area2 > r.area2;
    } else if (index != r.index) {
      return index > r.index;
    } else {
      // not important...just to make < complete
      return timestamp < r.timestamp;
    }
  }
};

ostream &operator<<(ostream &os, const pq_record &r)
{
  return os << "(" << r.index << ", " << r.area2 << ", " << r.timestamp
	    << ")";
}

list<Point> polyline;
int n, m;
list<Point>::iterator iter[1000001];  // iterators into each element
priority_queue<pq_record> pq;
int last[1000001];       // last timestamp for that point
bool removed[1000001];   // whether point has been removed

void add_triangle(int t, list<Point>::iterator it)
{
  if (it == polyline.begin()) return;
  auto it_prev = it;  it_prev--;
  auto it_next = it;  it_next++;
  if (it_next == polyline.end()) return;
  pq_record rec{t, it->index, *it_prev, *it, *it_next};
  //  cout << "Pushing " << rec << endl;
  pq.push(rec);
}

void solve()
{
  // initialize
  fill(removed, removed+n+1, false);
  fill(last, last+n+1, 0);
  int i = 0;
  for (auto it = polyline.begin(); it != polyline.end(); ++it) {
    iter[i] = it;
    if (i > 0 && i < n) {
      add_triangle(0, it);
    }
    i++;
  }

  // now remove points
  for (int i = 0; i < n-m; i++) {
    // find the next point to remove
    pq_record rec;
    while (true) {
      assert(!pq.empty());
      rec = pq.top();
      pq.pop();
      if (!removed[rec.index] && last[rec.index] == rec.timestamp)
	break;
    }

    cout << rec.index << endl;

    // now update the areas of the triangles before and after (if they
    // exist
    auto prev = iter[rec.index];  prev--;
    auto next = iter[rec.index];  next++;
    polyline.erase(iter[rec.index]);
    removed[rec.index] = true;
    
    add_triangle(i+1, prev);
    add_triangle(i+1, next);
    last[prev->index] = last[next->index] = i+1;
  }
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    Point p;
    p.read(i);
    polyline.push_back(p);
  }

  solve();
  
  return 0;
}
