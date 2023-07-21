#include <bits/stdc++.h>

using namespace std;

int main()
{
  int S, N;
  cin >> S >> N;

  int a[1001];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  a[N] = a[0] + S;

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int gap = a[i+1] - a[i] - 1;
    ans += (gap-1) / 2;
  }

  cout << ans << endl;


  return 0;
}
