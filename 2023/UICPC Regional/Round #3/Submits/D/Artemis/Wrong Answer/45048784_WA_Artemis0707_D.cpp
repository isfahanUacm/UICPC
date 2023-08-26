#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int sm(const string& a, int index) {
    if (index >= a.length()) {
        return 0;
    }
    int x = 0;
    for (int i = index; i < a.length(); ++i) {
        x += a[i] - '0';
    }
    return x;
}

long long tenp(int ind) {
    ll f = 1;
    for (int i = 0; i < ind; ++i) {
        f *= 10;
    }
    return f;
}

long long solve(long long x) {
    if (x < 0) {
        return 0;
    }
    int ind = 0;
    long long ans = 0;
    while (x != 0) {
        string a = to_string(x);
        reverse(a.begin(), a.end());
        if (a[ind] != '0') {
            long long prev = sm(a, ind + 1);
            ans += prev * (tenp(ind)) +
                    (a[ind] - '0') +
                    ((a[ind] - '0' - 1) * (tenp(ind) - 1)) +
                    45 * tenp(ind - 1) * (ind);

            a[ind]--;
            reverse(a.begin(), a.end());
            x = stoll(a);
        }
        else {
            ind++;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cout << solve(b) - solve(a - 1) << endl;
    }
}
