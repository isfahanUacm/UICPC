#include <bits/stdc++.h>
using namespace std;

array<int64_t, 3> take_step(array<int64_t, 3> X) {
  int64_t a = X[0], b = X[1], c = X[2];
  sort(begin(X), end(X));
  int64_t lo = X[0], mid = X[1], hi = X[2];

  int64_t A = 0, B = 0, C = 0;

  (b >= c ? B : C)++;
  (c >= a ? C : A)++;
  (a >= b ? A : B)++;
  return {a - A, b - B, c - C};
}

pair<int, int64_t> f(array<int64_t, 3> A) {
  int64_t a = A[0], b = A[1], c = A[2];
  sort(begin(A), end(A));
  int64_t lo = A[0], mid = A[1], hi = A[2];

  if (lo == 0) return {a == hi ? 0 : b == hi ? 1 : 2, hi - mid};
  if (a == b && b == c) return {-1, 0};

  if (mid < 50) return f(take_step({a, b, c}));
  
  if (a != b && b != c && a != c) {
    int64_t steps = min(mid - lo, hi - mid);
    return f({a - steps * ((a == hi) * 2 + (a == mid)),
              b - steps * ((b == hi) * 2 + (b == mid)),
              c - steps * ((c == hi) * 2 + (c == mid))
            });
  }

  if(lo == mid) { // lo lo hi -> lo-1 lo hi-2 -> lo-1 lo-1 hi-4
    int64_t two_steps = min(lo - 1, (hi - lo) / 3); // ZERO
    if(two_steps)
      return f({a - two_steps * ((a == hi) * 4 + (a == mid)),
                b - two_steps * ((b == hi) * 4 + (b == mid)),
                c - two_steps * ((c == hi) * 4 + (c == mid))
              });
    
    if (hi == lo + 2) return f(take_step({a, b, c}));

    // lo lo lo+1 -> lo-1 lo lo-1 -> lo-1 lo-2 lo-2 -> lo-3 lo-3 lo-2 
    lo %= 3;
    lo += 3;
    return f({lo + (a == hi) , lo + (b == hi), lo + (c == hi)});
  }

  // lo hi hi -> lo hi-1 hi-2 -> lo hi-3 hi-3
  int64_t two_steps = (hi - lo) / 3;
  if(two_steps > 0)
    return f({a - two_steps * ((a == hi) * 3),
              b - two_steps * ((b == hi) * 3),
              c - two_steps * ((c == hi) * 3)
              });
  
  // lo lo+2 lo+2 -> lo lo lo+1
  if(hi == lo + 2) return f(take_step({a, b, c}));

  // lo lo+1 lo+1
  lo %= 3;
  lo += 3;
  return f({lo + (a == hi) , lo + (b == hi), lo + (c == hi)});
}

void do_case() {
  int64_t a, b, c;
  cin >> a >> b >> c;

  auto [idx, val] = f({a, b, c});

  if(val == 0) cout << "Rubble!" << endl;
  else cout << char('A' + idx) << " " << val << endl;
}

int main() {
  do_case();
}
