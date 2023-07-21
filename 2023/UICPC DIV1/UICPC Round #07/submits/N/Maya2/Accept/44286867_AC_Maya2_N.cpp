
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
const int maxn = 100;
int gray[maxn];
int ss[5][maxn];
int word[maxn];

void solve() { 
    int n, w;
    cin >> n >> w;
    string green =  "nnnnn";
    vector<char> yellow;
    int y=0;
    vector<pair<char, int>> dup;
    string st1, st2;
    fori (0, 5) {
        if (st2[i] == 'G' || st2[i] == 'Y') word[st1[i]]++;
    }
    fori (0, n) {
        cin >> st1 >> st2;

        forj (0, 5) {
            if (st2[j] == 'G') {
                green[j] = st1[j];
            }
            else if (st2[j] == 'Y') {
                ss[j][st1[j]] = 1;
                yellow.push_back(st1[j]);
            }
            else {
                gray[st1[j]] = 1;
                if (word[st1[j]] > 0) {
                    dup.push_back({st1[j], word[st1[j]]});
                }
            }
        }
    }
    
    fori (0, w) {
        cin >> st1;
        bool ok= true;
        
        for (char x : yellow) {
            bool found = false;
            forj (0,5) {
                if (st1[j] == x) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                ok = false;
                break;
            }
        }
        for (auto x : dup) {
            int nn=0;
            forj (0, 5) {
                if (st1[j] == x.first) nn++;
            }
            if (nn != x.second) ok = false;
        }

        forj (0, 5) {
            if (!ok) break;
            // check greens
            if (green[j] != 'n') {
                if (st1[j] != green[j]) {
                    ok = false;
                    break;
                } else continue;
            }

            // check grays
            if (gray[st1[j]] == 1) {
                // if is not in yellows 
                if (find(yellow.begin(), yellow.end(), st1[j]) == yellow.end()) {
                    ok = false;
                    break;
                }
            } 

            // check yellows
            if (ss[j][st1[j]] == 1) {
                ok = false;
                break;
            }
        }

        if (ok) cout<<st1<<endll;
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    //int T; cin >> T; while (T--)
    solve();

    return 0;
}