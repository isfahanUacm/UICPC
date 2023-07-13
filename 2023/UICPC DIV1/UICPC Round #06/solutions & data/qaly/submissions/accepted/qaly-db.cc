#include <bits/stdc++.h>
using namespace std;

int readInt(){
  int x,y; char c;
  cin >> x >> c >> y;
  return x*10 + y;
}

int main(){
  int n; cin >> n;
  int ans = 0;

  for(int i=0;i<n;i++){
    int frac = readInt(), years = readInt();
    ans += frac * years;
  }

  cout << ans/100 << "." << setw(2) << setfill('0') << ans%100 << endl;
}
