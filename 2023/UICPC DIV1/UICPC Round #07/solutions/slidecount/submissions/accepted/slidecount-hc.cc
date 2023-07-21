#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, C;
  int w[100000];
  
  cin >> N >> C;
  for (int i = 0; i < N; i++) {
    cin >> w[i];
  }

  int s = 0, e = 0;
  int enter[100000];
  int t = 0;

  int total = w[0];
  enter[0] = t;

  while (s < N) {
    t++;
    if (e + 1 >= N || total + w[e+1] > C) {
      cout << t - enter[s] << endl;
      total -= w[s++];
    } else {
      total += w[++e];
      enter[e] = t;
    }
  }

  return 0;
}
