#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

int p[1010][1010],
    q[1010][1010];
queue<int> desc[1010];
int owner[1010],
    have[1010];

int startedPlaying[1010][1010],
    totalPlaytime[1010][1010];

int main() {
    memset(owner,-1,sizeof(owner));

    int n, m;
    scanf("%d %d", &n, &m);

    if (n > m) {
        printf("  \n   \n   IMPoSsIBle   \n");
        return 0;
    }

    int at = 2000000000;
    rep(i,0,n) {
        rep(j,0,m) {
            startedPlaying[i][j] = at--;
        }
    }

    int d, e;
    cin >> d >> e;

    vi cur(n, -1);
    rep(i,0,e) {
        int s, k, t;
        cin >> s >> k >> t;
        k--, t--;
        if (cur[k] != -1) {
            totalPlaytime[k][cur[k]] += s;
        }
        cur[k] = t;
        if (t != -1) {
            totalPlaytime[k][t] -= s;
            if (startedPlaying[k][t] > d) {
                startedPlaying[k][t] = s;
            }
        }
    }
    rep(i,0,n) {
        if (cur[i] != -1) {
            totalPlaytime[i][cur[i]] += d;
        }
    }

    rep(i,0,n) {
        vii arr;
        rep(j,0,m) {
            arr.push_back(ii(startedPlaying[i][j], j));
        }
        sort(arr.begin(), arr.end());
        rep(j,0,m) {
            p[i][arr[j].second] = j;
        }
    }
    rep(j,0,m) {
        vii arr;
        rep(i,0,n) {
            arr.push_back(ii(totalPlaytime[i][j], i));
        }
        sort(arr.begin(), arr.end());
        rep(i,0,n) {
            q[arr[i].second][j] = i;
        }
    }

    rep(i,0,n) {
        vii arr;
        rep(j,0,m) {
            arr.push_back(ii(p[i][j], j));
        }
        sort(arr.begin(), arr.end());
        rep(j,0,m) {
            desc[i].push(arr[j].second);
        }
    }

    queue<int> rem;
    rep(i,0,n) rem.push(i);

    while (!rem.empty()) {
        int kid = rem.front();
        rem.pop();

        assert(!desc[kid].empty());
        int toy = desc[kid].front();
        desc[kid].pop();

        if (owner[toy] == -1) {
            owner[toy] = kid;
        } else {
            int kid2 = owner[toy];
            if (q[kid][toy] < q[kid2][toy]) {
                owner[toy] = kid;
                rem.push(kid2);
            } else {
                rem.push(kid);
            }
        }
    }

    rep(i,0,m) {
        if (owner[i] != -1) {
            have[owner[i]] = i;
        }
    }

    rep(i,0,n) {
        printf(" \n  %d   \n    \n ", have[i]+1);
    }

    return 0;
}

