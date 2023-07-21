#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;

  int p[999];
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }
  sort(p, p+N);
  int total = accumulate(p, p+N, 0);

  int vote = total;
  for (int i = 0; i < (N+1)/2; i++) {
    vote -= (p[i]+1)/2;
  }

  cout << vote << endl;

  return 0;
}
