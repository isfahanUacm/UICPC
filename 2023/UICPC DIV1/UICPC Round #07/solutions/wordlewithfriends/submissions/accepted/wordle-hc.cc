#include <bits/stdc++.h>

using namespace std;

int N, W;
string g[10], f[10];

string result(string w, string g)
{
  string res(5, '-');
  for (int i = 0; i < 5; i++) {
    if (g[i] == w[i]) {
      res[i] = 'G';
      g[i] = 'a';
      w[i] = 'b';
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (g[i] == w[j]) {
	res[i] = 'Y';
	g[i] = 'a';
	w[j] = 'b';
      }
    }
  }
  return res;
}
 

bool check(string w)
{
  for (int i = 0; i < N; i++) {
    if (result(w, g[i]) != f[i]) {
      return false;
    }
  }
  return true;
}

int main()
{
  cin >> N >> W;

  for (int i = 0; i < N; i++) {
    cin >> g[i] >> f[i];
  }

  string dict[10000];
  for (int i = 0; i < W; i++) {
    cin >> dict[i];
  }

  for (int i = 0; i < W; i++) {
    if (check(dict[i])) {
      cout << dict[i] << endl;
    }
  }

  return 0;
}
