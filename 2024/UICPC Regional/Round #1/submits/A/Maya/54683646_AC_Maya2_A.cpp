#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

vector<string> split(const string &s, const char ch = ' ') {
    int n = s.size();
    vector<string> sp;

    string tmp;
    for (int i = 0; i < n; i++) {
        if (s[i] != ch) {
            tmp += s[i];
        }
        else if (tmp != "") {
            sp.push_back(tmp);
            tmp = "";
        }
    }
    if (tmp != "") {
        sp.push_back(tmp);
    }
    return sp;
}

char tur(int r) {
    if (r == 2 || r == 3 || r == 6 || r == 7 || r == 10 || r == 11 || r == 14 || r == 15 || r == 18 || r == 19 || r == 22 || r == 23)
        return 'b';
    return 'a';
}

void solve() {
    int n;
    cin >> n;

    int alice=-1, bob=-1;
    int lr=-1;
    bool ok=true;
    int notok=-1;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vector<string> ss = split(s, '-');
        int x = stoi(ss[0]);
        int y = stoi(ss[1]);
        if (x == 11 && y == 11) {
            if (ok) {
                ok = false;
                notok = i+1;
            }
        }

        int r = x+y+1;
        if (lr <= r) lr = r;
        else {
            if (ok) {
                ok = false;
                notok = i+1;
            }
        }
        if (tur(r) == 'b') {
            swap(x, y);
        }
        if (alice == 11 && y > bob) {
            if (ok) {
                ok = false;
                notok = i+1;
            }
        } else if (bob == 11 && x > alice) {
            if (ok) {
                ok = false;
                notok = i+1;
            }
        }

        if (x >= alice && y >= bob) {
            alice = x;
            bob = y;
        } else {
            if (ok) {
                ok = false;
                notok = i+1;
            }
        }
    }

    if (ok)
        cout << "ok" << endl;
    else 
        cout << "error " << notok << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
