#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> a(N), b(N);
  for (auto &x : a) {
    cin >> x;
  }
  for (auto &x : b) {
    cin >> x;
  }

  map<int,int> AmB, BmA;   // A-B, B-A
  for (int i = 0; i < N; i++) {
    if (a[i] != b[i]) {
      if (BmA.find(a[i]) != BmA.end()) {
	if (--BmA[a[i]] == 0) {
	  BmA.erase(a[i]);
	}
      } else {
	AmB[a[i]]++;
      }
      if (AmB.find(b[i]) != AmB.end()) {
	if (--AmB[b[i]] == 0) {
	  AmB.erase(b[i]);
	}
      } else {
	BmA[b[i]]++;
      }
    }
    cout << b[i] << ' ';
    if (!AmB.size() && !BmA.size() && i < N-1) {
      cout << "# ";
    }
  }
  cout << endl;

  return 0;
}
