#include <bits/stdc++.h>

using namespace std;

const string name[] = {"Alice", "Bob"};

// + = first win, - = first loss, 0 = tie
map<vector<int>, int> result;
vector<int> factors;

int f(vector<int> &curr)
{
  if (result.find(curr) != result.end())
    return result[curr];

  for (int i = 0; i < curr.size(); i++) {
    if (curr[i] > factors[i]) return 0;
  }

  int best = 1;
  for (int i = 0; i < curr.size(); i++) {
    curr[i]++;
    best = min(best, f(curr));
    curr[i]--;
  }

  return result[curr] = -best;
}

void solve()
{
  result.clear();
  factors.clear();
  
  int N;
  string first;
  
  cin >> N >> first;
  int first_i = find(name, name+2, first) - name;
  int second_i = 1-first_i;

  for (long long p = 2; p*p <= N; p++) {
    if (N % p == 0) {
      int f = 0;
      while (N % p == 0) {
	f++;
	N /= p;
      }
      factors.push_back(f);
    }
  }
  if (N > 1) {
    factors.push_back(1);
  }

  vector<int> curr((int)factors.size(),0);
  result[factors] = -1;
  int res = f(curr);

  if (res == 0) {
    cout << "tie" << endl;
  } else if (res > 0) {
    cout << name[first_i] << endl;
  } else {
    cout << name[second_i] << endl;
  }
}

int main()
{
  int T;
  cin >> T;
  while (T--)
    solve();

  return 0;
}
