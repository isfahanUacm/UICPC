#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807
#define end '\n' << flush

/* IN THE NAME OF GOD */

struct pack{
    ll x , y;
};

void solve() {
    int n;
    cout << "? 4 4" << end;
    cin >> n;
    if(n == 1){
        cout << "? 3 3" << end;
        cin >> n;
        if(n == 1){
            cout << "! 3 3" << end;
            return;
        }
        cout << "? 3 4" << end;
        cin >> n;
        if(n == 1){
            cout << "! 3 4" << end;
            return;
        }
        cout << "? 4 3" << end;
        cin >> n;
        if(n == 1){
            cout << "! 4 3" << end;
            return;
        }
        cout << "! 4 4" << end;
        return;
    }
    cout << "? 3 2" << end;
    cin >> n;
    if(n == 1){
        cout << "? 3 1" << end;
        cin >> n;
        if(n == 1){
            cout << "? 2 1" << end;
            cin >> n;
            if(n == 1){
                cout << "! 2 1" << end;
                return;
            }
            cout << "? 3 1" << end;
            return;
        }
        cout << "? 2 2" << end;
        cin >> n;
        if(n == 1){
            cout << "! 2 2" << end;
            return;
        }
        cout << "! 3 2" << end;
        return;
    }
    cout << "? 2 4" << end;
    cin >> n;
    if(n == 1){
        cout << "? 2 3" << end;
        cin >> n;
        if(n == 1){
            cout << "? 1 3" << end;
            cin >> n;
            if(n == 1){
                cout << "! 1 3" << end;
                return;
            }
            cout << "! 2 3" << end;
            return;
        }
        cout << "? 1 4" << end;
        cin >> n;
        if(n == 1){
            cout << "! 1 4" << end;
            return;
        }
        cout << "! 2 4" << end;
        return;
    }
    cout << "? 4 2" << end;
    cin >> n;
    if(n == 1){
        cout << "? 4 1" << end;
        cin >> n;
        if(n == 1){
            cout << "! 4 1" << end;
            return;
        }
        cout << "! 4 2" << end;
        return;
    }
    cout << "? 1 1" << end;
    cin >> n;
    if(n == 1){
        cout << "! 1 1" << end;
        return;
    }
    cout << "! 1 2" << end;
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