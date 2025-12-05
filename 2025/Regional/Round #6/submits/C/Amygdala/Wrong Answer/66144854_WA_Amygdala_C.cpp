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
#define pii pair<int, int>
#define F first
#define S second

const int N = 2e5+9;
pInt p[N];
vector<int> v[N];

void solve() {
    int n , k;
    cin >> n >> k;
    for(int i=0 ; i<n ; i++){
        v[i].clear();
        int a;
        cin >> a;
        p[i]={a , i};
        int x;
        cin >> x;
        for(int j=0 ; j<x ; j++){
            int b;
            cin >> b;
            v[i].push_back(b);
        }
    }

    sort(p , p+n);
    reverse(p , p+n);
//    for(int i=0 ; i<n ; i++){
//        for(int a : v[p[i].second])
//            cout << a<< " ";
//        cout << '\n';
//    }
    set<int> s;
    for(int i=0 ; i<n ; i++){
        map<int , int> cnt;
        int x = p[i].first;
        int j = i;
//        cout << j << ' ' << p[j].second << endl;
        for(; j<n && p[j].first == x ; j++){

            for(int gol : v[p[j].second]){
                cnt[gol]++;
            }
        }
        bool ok=0;
        for(auto & a : cnt){
//            cout << a.first << " " << a.second <<'\n';
            if(a.second == j-i && !s.contains(a.first)){
                ok=1;
                break;
            }
        }
        if(!ok){
            cout << "no" ;
            return;
        }
        j = i;
        for(; j<n && p[j].first == x ; j++){
            for(int gol : v[p[j].second]){
                s.insert(gol);
            }
        }
        if(s.size() > k+1-x){
            cout << "no" << endl;
            return;
        }
        i  = j-1;
    }

    cout << "yes" << endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
