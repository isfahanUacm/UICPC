#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>

void solve() {
    int n , m;
    cin >> n >> m;
    char s;
    cin >> s;
    int a , b , c;
    if(s == 'L'){
        c = n - m;
        b = m / 2;
        if(m % 2 != 0){
            b++;
        }
        a = b;
    }
    else{
        a = m - 1;
        b = (n - m + 1) / 2;
        if((n - m) % 2 == 0){
            b++;
        }
        c = b;
    }
    cout << a << " " << b << " " << c;
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