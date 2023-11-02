#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;

  typedef pair<int,string> pis;
  pis cup[20];

  for (int i = 0; i < N; i++) {
    string a, b;
    cin >> a >> b;
    if (isdigit(a[0])) {
      cup[i] = pis(stoi(a)/2, b);
    } else {
      cup[i] = pis(stoi(b), a);
    }
  }
  sort(cup, cup+N);
  for (int i = 0; i < N; i++) {
    cout << cup[i].second << endl;
  }

  return 0;
}
