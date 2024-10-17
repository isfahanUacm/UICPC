#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const maxI = 1e5*2;


void solve(){
 int n; cin >> n;
 double sum = 0;
 for(int i=0; i<n; i++)
 {
     int num; cin >> num;
     if(num == 0)
         sum += 2.0;
     else
         sum += 1.0/num;
 }
 cout << sum;
 return;
}

int main()
{
    solve();
    return 0;
}
