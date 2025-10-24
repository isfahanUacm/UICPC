#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';

int a[1009][50];
pair <int , pInt> p[1009];

bool cmp(pair <int , pInt> p1 , pair <int , pInt> p2){
    if(p1.second.first != p2.second.first)
        return (p1.second.first > p2.second.first);
    if(p1.second.second != p2.second.second)
        return p1.second.second < p2.second.second;
    return (p1.first < p2.first);
}

void solve()
{
    int n , m , q;
    cin >> n >> m >> q;
    for(int i=0 ; i<n ; i++){
        p[i] = {i+1 , {0 , 0}};
        for(int j=0 ; j<m ; j++){
            a[i][j]=0;
        }
    }
    while(q--){
        int time , qs , team , st;
        cin >> time >> team >> qs >> st;
        team--;
        qs--;
        if(a[team][qs] == -1)
            continue;
        if(st == 0){
            a[team][qs]++;
        }
        else{

            p[team].second={p[team].second.first + 1 , p[team].second.second + time + a[team][qs]*20};
            a[team][qs] = -1;
        }

    }
    sort(p , p+n , cmp);
    cout << 1 << ' ' << p[0].first << ' ' << p[0].second.first << ' ' << p[0].second.second << endl;
    int prev = 1;
    for(int i=1 ; i<n ; i++){
        if(p[i].second != p[i-1].second){
            prev = i+1;
        }
        cout << prev << ' ' << p[i].first << ' ' << p[i].second.first << ' ' << p[i].second.second << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<20; i++) cout << i << ':' << is_prime(i) << endl;
    return 0;
}