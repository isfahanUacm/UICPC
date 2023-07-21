#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, C;
  long long w[100000];
  
  cin >> N >> C;
  for (int i = 0; i < N; i++) {
    cin >> w[i];
  }

  long long psum[100000];
  partial_sum(w, w+N, psum);

  int s = 0, e = 0;
  int enter[100000];
  int t = 0;

  enter[0] = t;

  while (s < N) {
    t++;
    if (e + 1 >= N || psum[e+1] - (s > 0 ? psum[s-1] : 0) > C) {
      cout << t - enter[s++] << endl;
    } else {
      enter[++e] = t;
    }
  }

  return 0;
}
