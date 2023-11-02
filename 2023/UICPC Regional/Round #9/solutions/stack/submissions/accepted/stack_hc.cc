#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300;

// idea: you need exactly n print operations, so the question is really
// about optimizing pushes and pops

int memo[MAX_N+1][MAX_N+1];

int f(const string &s, int start, int end)
{
  int &res = memo[start][end];
  if (res != -1)
    return res;

  // base case: there is only one character.  Need to push and pop
  if (start == end)
    return res = 2;

  // you can always push and pop every single character
  res = 2*(end-start+1);

  // push that character on, print the first n-1 chars, and then print the
  // last character
  res = min(res, 2 + f(s, start, end-1));
  
  // we look at the last character.  We have to push it at some point
  // and pop it last.  But if that character appears in the string
  // before (index i), we could decide to print that first part with
  // only that character on the stack, process the rest, and then process
  // the last character
  //
  // there are no other ways to save work for the last character
  for (int i = start; i < end; i++) {
    // the pushing and popping of that last char is already counted in
    // f(start, i).  Also, note that f(start,i) may allow that same
    // last character to be reused multiple times so we don't have to
    // deal with that.
    if (s[i] == s[end])
      res = min(res, f(s, start, i) + f(s, i+1, end-1));
  }
  return res;
}

void solve()
{
  string s;

  getline(cin, s);
  int n = s.length();

  for (int i = 0; i <= n; i++) {
    fill(memo[i], memo[i]+n+1, -1);
  }
  
  cout << n + f(s, 0, n-1) << endl;
}

int main()
{
  int T;
  cin >> T;

  string line;
  getline(cin, line);
  while (T--)
    solve();
  
  return 0;
}
