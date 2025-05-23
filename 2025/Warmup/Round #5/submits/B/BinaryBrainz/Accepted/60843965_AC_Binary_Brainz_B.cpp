#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  endl '\n'
void solve() {
string s;
cin>>s;
ll n;
cin>>n;
 int in;
 int max = -1;
 int arr[26];
 for(int i =0 ; i< 26 ; i++){
    cin >> arr[i];
    if(arr[i] > max)
        max = arr[i];
 }

 ll sum = 0;
 for(int i =0 ; i<s.length()+n ; i++){
    sum += (i<s.length() ? arr[s[i]-'a']*(i+1) : max * (i+1));
 }

cout << sum;

}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
        if (t != 0)
            cout << '\n';
    }
}
