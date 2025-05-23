#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
#define pb push_back
#define pf push_front

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    int f = -1, e = -1, e2 = -1;

    for (int i = 0; i < min(m, n); i++) {
        if (s1[i] != s2[i]) {
            f = i;
            break;
        }
    }
    if (f == -1) {
        if (n >= m)
            cout << 0 << '\n';
        else 
            cout << m - n << '\n';
        return 0;
    }
    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--, j--) {
        if (s1[i] != s2[j]) {
            e = i;
            e2 = j;
            break;
        }
    } 
    if (e == -1) {
        if (n >= m)
            cout << 0 << '\n';
        else 
            cout << m - n << '\n';
        return 0;
    }

    if (n >= m) {
        cout << max(0, e - f + 1 - (n - m)) << '\n';
    }
    else {
        cout << max(e2 - f + 1, m - n) << '\n';
    }

    return 0;
}