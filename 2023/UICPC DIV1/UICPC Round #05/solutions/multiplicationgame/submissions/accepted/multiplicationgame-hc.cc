#include <bits/stdc++.h>

using namespace std;

const string name[] = {"Alice", "Bob"};

void solve()
{
  typedef pair<int,int> pii;
  vector<pii> factors;

  int N;
  string first;
  
  cin >> N >> first;
  int first_i = find(name, name+2, first) - name;
  int second_i = 1-first_i;

  for (long long p = 2; p*p <= N; p++) {
    if (N % p == 0) {
      pii f{p, 0};
      while (N % p == 0) {
	f.second++;
	N /= p;
      }
      factors.push_back(f);
    }
  }
  if (N > 1) {
    factors.push_back(pii{N, 1});
  }

  string result = "tie";
  if (factors.size() == 1) {
    result = (factors[0].second % 2 == 0) ? name[second_i] :
      name[first_i];
  } else if (factors.size() == 2) {
    if (factors[0].second == factors[1].second) {
      result = name[second_i];
    } else if (factors[0].second == factors[1].second+1 ||
	       factors[1].second == factors[0].second+1) {
      result = name[first_i];
    }
  }
  cout << result << endl;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
    solve();

  return 0;
}
