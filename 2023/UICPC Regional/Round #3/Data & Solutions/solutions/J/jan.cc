// [BAPC'12] John's book stack
// by: Jan Kuipers
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<vector<int>,long long> cache;

long long solve (vector<int> orig_x) {

  vector<int> x = orig_x;
  if (cache.count(x)) return cache[x];

  int i=1;
  while (i<x.size() && x[i-1]<=x[i]) i++;
  if (i==x.size()) return cache[orig_x] = 0;

  x.insert(x.begin(),x[i]);
  x.erase(x.begin()+i+1);

  i=1;
  while (i<x.size() && x[i]<x[0]) i++;

  long long res = 1 + solve(vector<int>(x.begin(),x.begin()+i));
  sort(x.begin(),x.begin()+i);
  res += solve(x);

  return cache[orig_x] = res;
}

int main () {

  int runs;
  cin >> runs;

  while (runs--) {

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i=0; i<n; i++)
      cin >> x[i];

    cache.clear();
    cout << solve(x) << endl;
  }

  return 0;
}
