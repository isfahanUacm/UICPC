#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define vi vector <int>

const int N = 2e5+9 , INF = 2e9;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int ans=0;
        for(int i=s.size()-1 ; i>=0 ; i--){
            if(s[i]!='0'){
                ans+=s.size()-1-i;
                for(int j=0 ; j<i ; j++)
                    if(s[j]!='0')ans++;
                break;
            }
        }
        cout << ans << endl;
    }
}


