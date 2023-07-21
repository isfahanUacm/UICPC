#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// from kactl
struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};
int w[100100];
int main() {
    int N, C;
    cin >> N >> C;
    for(int i = 1; i <= N; i++) cin >> w[i];
    int s = 1, e = 1;
    int acc = w[1] + w[2];
    FT ft(N+1);
    ft.update(1, 1);
    ft.update(2, -1);
    while (s <= N) {
        if (e+1>N || acc > C) {
            acc -= w[s]; s++;
            cout << ft.query(s) << endl;
        }
        else { e++; acc += w[e+1]; }
        ft.update(s, 1);
        ft.update(e + 1, -1);
    }
}
