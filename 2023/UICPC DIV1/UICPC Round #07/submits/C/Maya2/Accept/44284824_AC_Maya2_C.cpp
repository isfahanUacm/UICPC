// l a s h v
// Trick Taking (ABC 299)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endll '\n'
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fori(x, u) for (int i = x; i < u; ++i)
#define forj(x, u) for (int j = x; j < u; ++j)
#define sortv(a) sort(a.begin(), a.end())
#define ES cout << "YES\n"
#define NO cout << "NO\n"
// lower_bound -> greater than or equal
// upper_bound -> greater than
const int maxn = 1009;
int arr[maxn];

void solve() { 
    int s, n;
    cin >> s >> n;

    int a, b;
    fori (0, n) {
        cin >> a;
       arr[a-1] = 1;
    }

    int as=0;
    if (s >= 2 && arr[0] == 0) {
        if (arr[s-1] == 0 && arr[1] == 0) {
            arr[0] = 1;
            as++;
        } 
    }
    if (s >= 2 && arr[s-1] == 0) {
        if (arr[s-2]==0 && arr[0] == 0) {
            arr[s-1] = 1;
            as++;
        }
    }
    fori (1, s-1) {
        if (arr[i] == 0) {
            if (arr[i-1] == 0 && arr[i+1] == 0) {
                arr[i] = 1;
                as++;
            }
        }
    }

    cout << as;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    //int T; cin >> T; while (T--)
    solve();

    return 0;
}