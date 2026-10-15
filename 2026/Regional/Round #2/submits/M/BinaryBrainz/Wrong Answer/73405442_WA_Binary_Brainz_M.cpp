#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vl = vector<long long>;

vector<int> spf(1e6+1),ps;
void spf_gen()
{
    for (int i = 1; i <= 1e6+1; ++i) {  spf[i] = i;  }
    for (int i = 2; i * i <= 1e6+1; ++i) {
        if (spf[i] == i) {
            ps.push_back(i);
            for (int j = i * i; j <= 1e6+1; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}
int lg(int m, int p){
    int cnt= 0;
    while(m >= p){
        m/=p;
        cnt++;
    }
    return cnt;
};

void solve()
{
    int m;
    cin >> m;
    int ans = 0;
    for(auto &itr: ps){
        if(itr > m){
            break;
        }

        int cnt = 0;
        ll p = itr;
        while(p <= m){
            p *= p;
            cnt++;
        }
        ans+= cnt;
    }
    cout << ans + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    spf_gen();
    cin >> t;
    while (t--) {
        solve();
        if(t)cout<<endl;
    }
    return 0;
}