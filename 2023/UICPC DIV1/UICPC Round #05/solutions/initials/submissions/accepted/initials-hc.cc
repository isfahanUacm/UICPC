#include <bits/stdc++.h>

using namespace std;

int N;

struct Name
{
  string first, last;
  void read() {
    cin >> first >> last;
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    transform(last.begin(), last.end(), last.begin(), ::tolower);
  }

  bool operator<(const Name &n) const
  {
    return last+first < n.last + n.first;
  }

  int max_pad() const
  {
    return first.length() + last.length() - 2;
  }

  string pad(int k) const
  {
    string ans;
    ans += last[0];
    if (k > 0) {
      ans += last.substr(1, k);
    }
    k -= last.length()-1;
    ans += first[0];
    if (k > 0) {
      ans += first.substr(1, k);
    }
    return ans;
  }
};


const int MAX_N = 1000;
const int MAX_LEN = 80;
Name name[MAX_N];


const int INF = MAX_N*MAX_LEN*2;

int memo[MAX_N][MAX_LEN+1];

// min chars to add starting at name k in the list, if name k has m characters
// added to it.  Returns > MAX_N*MAX_LEN;
int f(int k, int m)
{
  if (k >= N-1) 
    return m;

  if (memo[k][m] >= 0)
    return memo[k][m];

  memo[k][m] = INF;
  string curr = name[k].pad(m);
  for (int mm = 0; mm <= name[k+1].max_pad(); mm++) {
    string next = name[k+1].pad(mm);
    if (curr >= next) continue;
    //    cout << "k, m, mm = " << k << " " << m << " " << mm << endl;
    memo[k][m] = min(memo[k][m], m + f(k+1, mm));
    //    cout << "  f = " << m+f(k+1,mm) << endl;
  }
  return memo[k][m];
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; i++) {
    name[i].read();
  }
  sort(name, name+N);

  for (int i = 0; i < N; i++) {
    for (int m = 0; m <= name[i].max_pad(); m++) {
      memo[i][m] = -1;
    }
  }

  int ans = INF;
  for (int m = 0; m <= name[0].max_pad(); m++) {
    ans = min(ans, f(0, m));
  }

  cout << ans << endl;
  return 0;
}
