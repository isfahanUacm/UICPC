#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_N = 200000;
int main()
{
  ll N, K;
  cin >> N >> K;

  int house[MAX_N+2];
  for (int i = 0; i < K; i++) {
    cin >> house[i];
  }
  house[K] = 0;
  house[K+1] = N+1;
  sort(house, house+K+2);

  ll ans = N*(N-1)/2 + N;
  for (int i = 0; i < K+1; i++) {
    ll gap = house[i+1]-house[i]-1;
    ans -= gap*(gap-1)/2 + gap;
  }

  cout << ans << endl;
  return 0;
}
