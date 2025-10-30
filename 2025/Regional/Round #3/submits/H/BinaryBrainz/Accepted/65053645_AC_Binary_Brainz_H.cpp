#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    string s1 , s2 , s3 , ans;
    cin >> s1 >> s2 >> s3;
    int a = 0 , b = 0 , c = 0;
    int size1 = s1.size() , size2 = s2.size() , size3 = s3.size();
    while(a < size1 || b < size2 || c < size3){
        if(s1[a] == s2[b]){
            ans += s1[a];
            a++;
            b++;
        }
        else if(s1[a] == s3[c]){
            ans += s1[a];
            a++;
            c++;
        }
        else if(s2[b] == s3[c]){
            ans += s2[b];
            b++;
            c++;
        }
    }
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}