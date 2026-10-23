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

int a[N] , sum[N];
vector<int> vec , cnt;

int bs(int ind , int n){
    int l=ind , r=n;
    while(r-l > 1){
        int mid=(l+r)/2;
        if(vec[mid]-vec[ind] < sum[mid]-sum[ind]+cnt[ind]){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    return l;
}

void solve() {
    int n;  cin >> n;
    vec.clear();
    cnt.clear();
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    sort(a , a+n);
    vec.push_back(a[0]);
    cnt.push_back(1);
    for(int i=1 ; i<n ; i++){
        if(a[i]!=a[i-1]){
            vec.push_back(a[i]);
            cnt.push_back(1);
        }
        else{
            cnt.back()++;
        }
    }
    sum[0]=cnt[0];
    for(int i=1 ; i<cnt.size() ; i++){
        sum[i]=sum[i-1]+cnt[i];
    }
    int ans=1;

    for(int i=0 ; i<vec.size() ; i++){
        int x = bs(i , vec.size());
        ans=max(ans , sum[x]-sum[i]+cnt[i]);
    }
    cout << n-ans << endl;
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