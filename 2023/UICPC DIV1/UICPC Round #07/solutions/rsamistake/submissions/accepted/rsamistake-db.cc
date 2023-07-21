#include <bits/stdc++.h>
using namespace std;

vector<int64_t> factor(int64_t n) {
  vector<int64_t> res;
  for(int64_t p=2;p*p<=n;p++)
    while(n % p == 0) {
      res.push_back(p);
      n /= p;
    }
  if(n > 1) res.push_back(n);
  return res;
}

string do_case() {
  int64_t a, b;
  cin >> a >> b;
  vector<int64_t> x = factor(a), y = factor(b);
  if(x.size() == 1 && y.size() == 1 && x != y) return "full credit";

  set<int64_t> M;
  for(auto v : x) if(!M.insert(v).second) return "no credit";
  for(auto v : y) if(!M.insert(v).second) return "no credit";

  return "partial credit";
}

int main() {
  cout << do_case() << endl;  
}
