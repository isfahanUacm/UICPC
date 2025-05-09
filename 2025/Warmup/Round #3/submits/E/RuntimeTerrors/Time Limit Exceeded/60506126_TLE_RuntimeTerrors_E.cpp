#include <bits/stdc++.h>

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
    ll n,m,q;
    cin>>n>>m>>q;
    int desks[n],monitors[n];
    vector <vector<int>> neighbor(n);
    for(ll i=0;i<n;++i)
        cin>>desks[i];
    for(ll i=0;i<n;++i)
        cin>>monitors[i];
    for(ll i=0;i<m;++i)
    {
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;

        neighbor[tmp1-1].push_back(tmp2-1);
        neighbor[tmp2-1].push_back(tmp1-1);
    }
    for (ll i = 0; i < q; i++) {
        string s;
        cin >> s;

        int num;
        cin >> num;
        if (s == "check") {
            ll sumd = desks[num - 1], summ = monitors[num - 1];

            for (ll j = 0; j < neighbor[num - 1].size(); j++) {
                sumd += desks[neighbor[num - 1][j]];
                summ += monitors[neighbor[num - 1][j]];
            }

            if (sumd == summ) cout << "same" << endl;
            else if (sumd > summ) cout << "desks" << endl;
            else cout << "monitors" << endl;
        } else {
            string dm;
            cin >> dm;

            int idx;
            cin >> idx;

            if (dm == "desk") {
                desks[idx - 1] += num;
            } else {
                monitors[idx - 1] += num;
            }
        }
    }
}