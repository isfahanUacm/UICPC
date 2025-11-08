#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back

const int N = 2e5+9;


void solve()
{
    cout << "? " << 3 << ' ' << 2 << endl;
    int ans;
    cin >> ans;
    if(ans == 1){
        cout << "? " << 2 << ' ' << 1 << endl;
        cin >> ans;
        if(ans == 1){
            cout << "! " << 2 << ' ' << 1 << endl;
            return;
        }
        cout << "? " << 2 << ' ' << 3 << endl;
        cin >> ans;
        if(ans == 1){
            cout << "! " << 2 << ' ' << 2 << endl;
            return;
        }
        cout << "? " << 4 << ' ' << 1 << endl;
        cin >> ans;
        if(ans == 1){
            cout << "! " << 3  << ' ' << 1 << endl;
            return;
        }
        cout << "! " << 3 << ' ' << 2 << endl;
        return;
    }
    cout << "? " << 2 << ' ' << 4 << endl;
    cin >> ans;
    if(ans == 1){
        cout << "? " << 1 << ' ' << 3 << endl;
        cin >> ans;
        if(ans == 1){
            cout << "! " << 1 << ' ' << 3 << endl;
            return;
        }
        cout << "? " << 1 << ' ' << 5 << endl;
        cin >> ans;
        if(ans == 1){
            cout << "! " << 1 << ' ' << 4 << endl;
            return;
        }
        cout << "? " << 3 << ' ' << 3 << endl;
        cin >> ans;
        if(ans == 1){
            cout << "! " << 2  << ' ' << 3 << endl;
            return;
        }
        cout << "! " << 2 << ' ' << 4 << endl;
        return;
    }
    cout << "? " << 4 << ' ' << 4 << endl;
    cin >> ans;
    if(ans == 1){
        cout << "? " << 3 << ' ' << 4 << endl;
        cin >> ans;
        if(ans == 1){
            cout << "? " << 3 << ' ' << 3 << endl;
            cin >> ans;
            if(ans == 1){
                cout << "! " << 3 << ' ' << 3 << endl;
            }
            else
                cout << "! " << 3 << ' ' << 4 << endl;
            return;
        }
        cout << "? " << 5 << ' ' << 3 << endl;
        cin >> ans;
        if(ans == 1){
            cout << "! " << 4 << ' ' << 3 << endl;
            return;
        }
        cout << "! " << 4 << ' ' << 4 << endl;
        return;
    }
    cout << "? " << 2 << ' ' << 2 << endl;
    cin >> ans;
    if(ans == 1){
        cout << "? " << 2 << ' ' << 1 << endl;
        cin >> ans;
        if(ans == 1){
            cout << "! " << 1 << ' ' << 1 << endl;
            return;
        }
        cout << "! " << 1 << ' ' << 2 << endl;
        return;
    }
    cout << "? " << 5 << ' ' << 1 << endl;
    cin >> ans;
    if(ans == 1){
        cout <<"! " <<  4 << ' ' << 1 << endl;
    }
    else{
        cout << "! 4 2" << endl;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}