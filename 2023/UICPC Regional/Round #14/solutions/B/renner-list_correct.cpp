// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;

typedef unsigned long ul;

#define MAX_BOOKS  10000

typedef struct {
  unsigned long a, d;
} booking_t;


bool operator< (const booking_t & x, const booking_t & y) {
  return x.a < y.a;
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

void tc() {
  list<booking_t> books;
  ul B, C;

  cin >> B >> C;
  while (B--) {
    booking_t b;
    string dummy;
    cin >> dummy;
    b.a = readDate();
    b.d = readDate();
    books.push_back(b);

    //cout << b.a << " -> " << b.d << endl;
  }

  // ALGORITHM
  ul res = 0;
  books.sort();

  while (! books.empty()) {
    res++;

    ul end = books.front().d;
    books.pop_front();
    
    for (list<booking_t>::iterator it = books.begin(); it != books.end();) {
      if (it->a >= end + C) {
        end = it->d;
        it = books.erase(it);
      } else {
        it++;
      }
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
