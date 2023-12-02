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
  unsigned long a, d;
} booking_t;


bool operator< (const booking_t & x, const booking_t & y) {
  return x.a < y.a;
//  return x.a < y.a || (x.a == y.a && x.d > y.d);
//  return x.a < y.a || (x.a == y.a && x.d < y.d);
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

bool taken[MAX_BOOKS];
void tc() {
  vector<booking_t> books;
  ul B, C;

  cin >> B >> C;
  while (B--) {
    booking_t b;
    string dummy;
    cin >> dummy;
    b.a = readDate();
    b.d = readDate();
    books.push_back(b);
  }

  // ALGORITHM
  ul res = 0;
  memset(taken, 0, sizeof(taken));
  sort(books.begin(), books.end());

  for (ul i = 0; i < books.size(); i++) {
    if (taken[i]) continue;

    res++;

    ul end = books[i].d;
    
    for (ul j = i + 1; j < books.size(); j++) {
      if (taken[j]) continue;

      if (books[j].a >= end + C) {
        end = books[j].d;
        taken[j] = true;
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
