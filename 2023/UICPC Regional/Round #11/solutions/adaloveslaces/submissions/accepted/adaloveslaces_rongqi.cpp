#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
double d, s, t, f_min, f_max, l;

double segment(int i, int j) {
  return sqrt(s * s + d * d * fabs(j - i) * fabs(j - i));
}

int patterns(int i, vector<bool>& visited, double len) {
  if (i == 0) {
    if (l - len * 2 - s >= f_min * 2 && l - len * 2 - s <= f_max * 2) {
      return 1;
    } else {
      return 0;
    }
  }
  visited[i] = true;
  int ans = 0;
  // same side
  if (i != n - 1 && !visited[i + 1]) {
    ans += patterns(i + 1, visited, len + d + t);
  }
  if (!visited[i - 1]) {
    ans += patterns(i - 1, visited, len + d + t);
  }
  // other side
  for (int j = 0; j < n; ++j) {
    if (!visited[j]) {
      ans += patterns(j, visited, len + segment(i, j) + t);
    }
  }
  visited[i] = false;
  return ans;
}

int main() {
  cin >> n >> d >> s >> t >> f_min >> f_max;
  while (cin >> l) {
    vector<bool> visited(n);
    cout << patterns(n - 1, visited, t) << endl;
  }
  return 0;
}