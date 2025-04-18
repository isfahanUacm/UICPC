#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n, b; cin >> n >> b;
    vector<int> branch(b);
    loop(b, i) cin >> branch[i];
    std::sort(branch.begin(), branch.end());
    int l = b;
    int sum = 0;
    for(int i=0; i<l; i++)
        sum += branch[i] * (l-i);
    sum += n;

    cout << sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
//    cin >> n;
    while(n--)
        solve();

    return 0;
}