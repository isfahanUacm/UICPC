#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>

void solve() {
    int n;
    cin >> n;
    string s1 , s2;
    cin >> s1 >> s2;
    char ans[n];
    for (int i = 0; i < n / 2; ++i) {
        int l1 = min(int(s1[i]) , int(s1[n - 1 - i]));
        int r1 = max(int(s1[i]) , int(s1[n - 1 - i]));
        int l2 = min(int(s2[i]) , int(s2[n - 1 - i]));
        int r2 = max(int(s2[i]) , int(s2[n - 1 - i]));
        if(l1 >= r2){
            int sum = (r2 + l1) / 2;
            ans[i] = char(sum);
            ans[n - 1 - i] = ans[i];
        }
        else if(l2 >= r1){
            int sum = (r1 + l2) / 2;
            ans[i] = char(sum);
            ans[n - 1 - i] = ans[i];
        }
        else{
            int L = max(l1 , l2);
            int R = min(r1 , r2);
            int sum = (R + L) / 2;
            ans[i] = char(sum);
            ans[n - 1 - i] = ans[i];
        }
    }
    int size = n / 2;
    if(n % 2 != 0){
        int sum = s1[size] + s2[size];
        sum /= 2;
        ans[size] = sum;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}