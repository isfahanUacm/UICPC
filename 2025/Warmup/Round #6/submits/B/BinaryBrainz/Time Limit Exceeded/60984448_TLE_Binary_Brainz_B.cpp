#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
struct pairs{
    char c;
    ll ind;
};
set<ll> st;
bool prime(ll n)
{
    if(st.find(n) !=st.end()){
        return true;
    }
    for(auto &itr : st){
        if(itr > sqrt(n))
            break;

        if(n % itr == 0){
            return false;
        }
    }

    st.insert(n);
    return true;
}
void fill()
{
    st.insert(2);
    for (int i = 3; i <= 1000000; i+=2) {
        prime(i);
    }
}
void solve() {
    ll n;
    cin>>n;
    if(n%2==0)
    {
        cout<< n/2<<' '<<n/2;
        return;
    }
    else
    {
        for (int i = 3; i <= n; i+=2) {
            if(i<=1000000)
            {
                if(st.find(i)!=st.end())
                {
                    if(n%i==0)
                    {
                        cout<<n/i<<' '<<(n-(n/i));
                        return;
                    }
                }
            }
            if(prime(i))
            {
                if(n%i==0)
                {
                    cout<<n/i<<' '<<(n-(n/i));
                    return;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fill();
    int t=1;
    cin >> t;
    while (t--) {
        solve();
        if (t) cout << '\n';
    }
    return 0;
}
