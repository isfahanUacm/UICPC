#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const maxI = 1e5*2;
double sum=0;
int arr[10000];
void solve(){
 int n ; cin >> n;
 for(int i =0 ; i < n ;i++)
 {
     double num;cin>>num;
     if(num ==0)
     {
         sum+=2;
     }else
     {
         sum+=double(1/num);
     }
 }
 cout << setprecision(6)<< sum << '\n';
 return;
}

int main()
{
    solve();
    return 0;
}
