#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  map<int, int> M;
  for (auto &A : a)
    cin >> A;
  for (auto &B : b)
    cin >> B;

  int diff = 0;
  for (int i = 0; i < N; i++) {
    cout << b[i] << " ";
    int v1 = M[a[i]], v2 = M[b[i]];
    M[a[i]]--;
    M[b[i]]++;

    if (v1 == 0 && M[a[i]] != 0)
      diff++;
    if (v2 == 0 && M[b[i]] != 0)
      diff++;
    if (v1 != 0 && M[a[i]] == 0)
      diff--;
    if (v2 != 0 && M[b[i]] == 0)
      diff--;

    if (diff == 0 && i != N - 1) {
      cout << "# ";
    }
  }
  cout << endl;
}
