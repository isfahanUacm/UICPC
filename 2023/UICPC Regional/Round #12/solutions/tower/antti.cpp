#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
map<int,vector<int>> v;
map<int,vector<int>> w;
vector<int> s;

map<int,int> c, d;
vector<int> u;
bool z;

void dfs(int x, int e) {
    if (c[x]) {
        z = true;
        return;
    }
    c[x] = 1;
    for (int i = 0; i < v[x].size(); i++) {
        if (v[x][i] == e) continue;
        if (!d[w[x][i]]) {
	    u.push_back(x);
            u.push_back(v[x][i]);
	    d[w[x][i]] = 1;
        }
        dfs(v[x][i], x);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        w[a].push_back(i);
        v[b].push_back(a);
        w[b].push_back(i);
        s.push_back(a);
        s.push_back(b);
    }
    sort(s.begin(),s.end());
    ll r = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && s[i-1] == s[i]) continue;
        u.clear();
        z = false;
        dfs(s[i],0);
        sort(u.begin(),u.end());
        int p = 0;
        //cout << "uusi " << s[i] << "\n";
        for (int i = 0; i < u.size(); i++) {
            if (i == 0 || u[i-1] != u[i]) {
                int c = 0;
                for (int j = i; j < u.size(); j++) {
                    if (u[i] != u[j]) break;
                    c++;
                }
                //cout << c << " " << u[i] << "\n";
                p = max(p,u[i]);
                if (c >= 2) {
                    r += (ll)(c-1)*u[i];
                }
            }
        }
        if (!z) r += p;
    }
    cout << r << "\n";
}
