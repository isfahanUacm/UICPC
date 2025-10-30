#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back


void solve()
{
   string s1 , s2 , s3;
   cin >> s1 >> s2 >> s3;
   int i1=0 , i2=0 , i3=0;
   vector<char> ans;
   while(i1<s1.size() || i2<s2.size() || i3<s3.size()){
       if(i1<s1.size() && i2<s2.size() && s2[i2] == s1[i1]){
           ans.pb(s1[i1]);
           i1++;
           i2++;
       }
       else if(i1<s1.size() && i3<s3.size() && s1[i1] == s3[i3]){
           ans.pb(s1[i1]);
           i1++;
           i3++;
       }
       else{
           ans.pb(s2[i2]);
               i2++;
               i3++;
       }


   }
    for(char c : ans){
        cout << c;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<20; i++) cout << i << ':' << is_prime(i) << endl;
    return 0;
}