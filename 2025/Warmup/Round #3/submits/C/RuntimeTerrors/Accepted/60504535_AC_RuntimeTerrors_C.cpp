#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vll;

void solve();

template<class T>
void printArray(T *arr, size_t size) {
    if (!size) return;
    for (size_t i = 0; i < size - 1; i++) {
        cout << arr[i] << ' ';
    }
    cout << arr[size - 1];
}

template<class T>
ostream &operator<<(ostream &os, const vector <T> &vec) {
    if (!vec.size()) return os;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        os << vec[i] << ' ';
    }
    os << vec.back();
    return os;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout << setprecision(10);
    ll t=1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}

void solve() {
    ll s,n;
    cin>>s>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin >> arr.at(i);
    }
    sort(arr.begin(), arr.end());
    for(ll i=0;i<n;++i)
        if(s%arr.at(i)==0)
        {
            ll temp=s/arr.at(i);
            if(binary_search(arr.begin(), arr.end(), temp))
            {
                cout<<arr.at(i)<<" "<<temp;
                return;
            }
        }
}