#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define int ll
#define endl '\n'

int const N =  1e6+9;
int const INF = 1e9;
ll const mod = 1e9;

int a[N];

void solve() {
    ll n,k;  cin >> n >> k;
    vector<int> v(n);
    vector<ll> sum(n);
    cin >> v[0];
    sum[0] = v[0];
    for(int i=1; i<n; i++){
        cin >> v[ i];
        sum[i] = sum[i-1]+v[i];
    }
    vector<int> cnt(n);
    int last = v[0];
    cnt[0] = 1;
    if(v[0] < 1){
        cout << sum[0] + (k*(k+1))/2;
    }
    else
        cout << k+sum[0];
    set<int> s;
    s.insert(v[0]);
    for(int i=1; i<n; i++){
        cnt[i] = cnt[i-1];
        last = *s.rbegin();
        s.insert(v[i]);
        if(*s.rbegin() > last){
            cnt[i]++;
        }
        else {
            s.erase(--s.end());
        }
        last = *s.rbegin();

        if(cnt[i] > last){
            cout << " " << sum[i]+ ((cnt[i]+k)*(cnt[i]+k-1))/2 - ((cnt[i]-1)*cnt[i])/2;
        }
        else{
            cout << " " << sum[i]+k*cnt[i];
        }
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}