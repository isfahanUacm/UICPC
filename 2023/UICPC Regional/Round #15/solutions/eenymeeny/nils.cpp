#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    getline(cin,s);
    int spaces = 0;
    rep(c1,0,s.length()){
        spaces += (s[c1] == ' ');
    }
    cin >> n;
    vector<string> names(n);
    vi team;
    vector<pii> order;
    rep(c1,0,n){
        cin >> names[c1];
        team.push_back(0);
        order.push_back({0,c1});
    }

    int kid = 0;
    rep(c1,0,n){
        int seen = 0;
        while(seen <= spaces){
            seen += (team[kid] == 0);
            if(seen == spaces+1){
                team[kid] = c1%2+1;
                order[kid].first = c1;
            }
            kid++;
            kid %= n;
        }
    }

    sort(all(order));  // unnecessary?

    cout << n/2+n%2 << "\n";
    rep(c2,0,n){
        int c1 = order[c2].second;
        if(team[c1] == 1)cout << names[c1] << "\n";
    }
    cout << n/2 << "\n";
    rep(c2,0,n){
        int c1 = order[c2].second;
        if(team[c1] == 2)cout << names[c1] << "\n";
    }


    return 0;
}


