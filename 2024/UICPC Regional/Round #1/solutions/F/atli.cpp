#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi kmppi(string &p) {
  int m = p.size(), i = 0, j = -1; vi b(m + 1, -1);
  while(i < m) { while(j >= 0 && p[i] != p[j])
    j = b[j]; b[++i] = ++j; } return b; }

vi kmp(string &s, string &p) {
  int n = s.size(), m = p.size(), i = 0, j = 0;
  vi b = kmppi(p), a = vi(); while(i < n) {
    while(j >= 0 && s[i] != p[j]) { j = b[j]; }
    ++i; ++j; if(j == m) { a.push_back(i - j);
      j = b[j]; } } return a; }

vi solve_len(vector<set<int>> &poss, vector<vector<string>> &mat, int len0) {
    int n = poss.size();
    vi res(n);
    res[0] = len0;
    for(int i = 1; i < n; ++i) {
        res[i] = mat[0][i].size() - res[0];
    }
    for(int i = 0; i < n; ++i) {
        if(!poss[i].count(res[i])) {
            return vi();
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            if(res[i] + res[j] != mat[i][j].size()) {
                return vi();
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<string>> mat(n, vector<string>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }
    vi upper(n, INT_MAX);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(mat[i][j].size() != mat[j][i].size()) {
                cout << "NONE\n";
                return 0;
            }
            if(i == j) continue;
            upper[i] = min(upper[i], (int) mat[i][j].size() - 1);
            upper[j] = min(upper[j], (int) mat[i][j].size() - 1);
        }
    }
    for(int i = 0; i < n; ++i) {
        int cmn = 0;
        while(cmn < upper[i]) {
            bool same = true;
            char c = i == 0 ? mat[i][1][cmn] : mat[i][0][cmn];
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                if(mat[i][j][cmn] != c) {
                    same = false;
                    break;
                }
            }
            if(!same) break;
            cmn++;
        }
        upper[i] = min(upper[i], cmn);
    }
    for(int j = 0; j < n; ++j) {
        int cmn = 0;
        while(cmn < upper[j]) {
            bool same = true;
            char c = j == 0 ? mat[1][j][mat[1][j].size() - 1 - cmn] : mat[0][j][mat[0][j].size() - 1 - cmn];
            for(int i = 0; i < n; ++i) {
                if(i == j) continue;
                if(mat[i][j][mat[i][j].size() - 1 - cmn] != c) {
                    same = false;
                    break;
                }
            }
            if(!same) break;
            cmn++;
        }
        upper[j] = min(upper[j], cmn);
    }
    vector<set<int>> poss(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= upper[i]; ++j) {
            poss[i].insert(j);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            string pat = mat[i][j] + mat[i][j];
            vi inds = kmp(pat, mat[j][i]);
            set<int> itsct;
            for(int k : inds) {
                if(poss[i].count(k)) {
                    itsct.insert(k);
                }
            }
            poss[i] = itsct;
            if(poss[i].empty()) {
                cout << "NONE\n";
                return 0;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        set<int> cpy = poss[i];
        for(int k : cpy) {
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                if(!poss[j].count(mat[i][j].size() - k)) {
                    poss[i].erase(k);
                }
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        if(poss[i].empty()) {
            cout << "NONE\n";
            return 0;
        }
    }
    vi ans;
    for(int z : poss[0]) {
        vi res = solve_len(poss, mat, z);
        if(res.empty()) continue;
        if(ans.size() == 0) {
            ans = res;
        } else {
            cout << "MANY\n";
            return 0;
        }
    }
    if(ans.empty()) {
        cout << "NONE\n";
        return 0;
    }
    cout << "UNIQUE\n";
    for(int i = 0; i < n; ++i) {
        string s = i == 0 ? mat[i][1] : mat[i][0];
        while(s.size() > ans[i]) s.pop_back();
        cout << s << '\n';
    }
}
