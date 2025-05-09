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
    ll desks[n],monitors[n];
    ll sumd[n], summ[n];
    vector <vector<int>> neighbor(n);
    for(ll i=0;i<n;++i) {
        cin>>desks[i];
        sumd[i] = desks[i];
    }
    for(ll i=0;i<n;++i) {
        cin>>monitors[i];
        summ[i] = monitors[i];
    }
    for(ll i=0;i<m;++i)
    {
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;

        neighbor[tmp1-1].push_back(tmp2-1);
        neighbor[tmp2-1].push_back(tmp1-1);

        sumd[tmp1-1] += desks[tmp2-1];
        sumd[tmp2-1] += desks[tmp1-1];

        summ[tmp1-1] += monitors[tmp2-1];
        summ[tmp2-1] += monitors[tmp1-1];
    }
    for (ll i = 0; i < q; i++) {
        string s;
        cin >> s;

        int num;
        cin >> num;
        if (s == "check") {
            if (sumd[num - 1] == summ[num - 1]) cout << "same" << endl;
            else if (sumd[num - 1] > summ[num - 1]) cout << "desks" << endl;
            else cout << "monitors" << endl;
        } else {
            string dm;
            cin >> dm;

            int idx;
            cin >> idx;

            if (dm == "desk") {
                desks[idx - 1] += num;
                sumd[idx - 1] += num;

                for (ll j = 0; j < neighbor[idx - 1].size(); j++) {
                    sumd[neighbor[idx - 1][j]] += num;
                }
            } else {
                monitors[idx - 1] += num;
                summ[idx - 1] += num;

                for (ll j = 0; j < neighbor[idx - 1].size(); j++) {
                    summ[neighbor[idx - 1][j]] += num;
                }
            }
        }
    }
}