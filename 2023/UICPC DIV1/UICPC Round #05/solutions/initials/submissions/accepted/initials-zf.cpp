#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cstring>

#define MAXN 1000
#define MAXL 80

using namespace std;

pair<string, int> names[MAXN];
int n, val[MAXN][MAXL-1];

string form(int i, int k) {
    if (k+1 <= names[i].second)
        return names[i].first.substr(0, k+1)+names[i].first[names[i].second];
    else
        return names[i].first.substr(0, k+2);
}

int solve(int i, int k) {
    if (val[i][k] == -1) {
        if (i == 0) val[i][k] = k;
        else {
            val[i][k] = MAXN*MAXL;
            string s = form(i, k);
            for (int kk = 0; kk < names[i-1].first.length()-1; ++kk) {
                if (form(i - 1, kk) < s) val[i][k] = min(val[i][k], solve(i-1, kk) + k);
            }
        }
    }

    return val[i][k];
}

int main() {
    memset(val, -1, sizeof(val));

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string first, last;
        cin >> first >> last;
        names[i].first = last+first;
        names[i].second = last.length();
        for (auto& x : names[i].first) x = tolower(x);
    }

    sort(names, names + n);

    int best = MAXN*MAXL;
    for (int k = 0; k < names[n-1].first.length()-1; ++k)
        best = min(best, solve(n-1, k));

    cout << best << endl;

    return 0;
}
