// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define MAX_BOOKS  10000

typedef unsigned long ul;

typedef struct {
  unsigned long t;
  bool arrival;
} event_t;


bool operator< (const event_t & x, const event_t & y) {
  // sort by time and enforce departures before arrivals (makes algorithm easier)
  return (x.t < y.t) || ( (x.t == y.t) && (!x.arrival && y.arrival));
}


ul readDate() {
  ul Y, M, D, h, m;
  ul d;
  char dummy;
  cin >> Y >> dummy >> M >> dummy >> D >> h >> dummy >> m;
  
  d = (Y - 2013) * 365 + (M - 1) * 30 + (D - 1);
  if (M > 2) {
    d--; // february
    if (Y % 4) d--;  // no leap-year (only works for the given year range)
  }
  while (--M) {
    if ((M <= 7 && M % 2) || (M > 7 && !(M % 2))) d++;
 
  }
  return m + 60 * (h + 24 * d);
}

vector<event_t> q;
void tc() {
  q.clear();
  ul B, C;

  cin >> B >> C;
  while (B--) {
    event_t a, b;
    string dummy;
    cin >> dummy;

    a.t = readDate();
    a.arrival = true;
    q.push_back(a);

    b.t = C + readDate();
    b.arrival = false;
    q.push_back(b);
  }

  // ALGORITHM
  ul res = 0, cur = 0;
  sort(q.begin(), q.end());

  for (ul i = 0; i < q.size(); i++) {
    if (q[i].arrival) {
      cur++;
      res = max(cur, res);
    } else {
      cur--;
    }
  }
 
  cout << res << endl; 
}


int main() {
  unsigned T;

  cin >> T;
  while (T--) tc();
  return 0;
}
