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

vi v;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ld n, x;
    int i = 1;
    cin >> n;

    if (n == 1) {
        for (int i = 2; i <= 8; i++) {
            for (int j = 1; j <= 9; j++) {
                for (int k = 0; k < i; k++) 
                    cout << j;
                cout << '\n';
            }

        }
        return 0;
    }
    else if (n == 3) {
        cout << "142857\n285714\n";
        return 0;
    }
    else if (n == 1.5 || n == 2.5 || n == 4 || n == 5 || n == 6 || n == 7 || n == 8) {
        cout << "No solution\n";
        return 0;
    }
    x = n;
    while (x != int(x)) {
        x = n * i++;
    }
    
    int z = x;
    i = 1;
    while (z < 1e8) {
        z = x * i++;
        int zz = z / n;
        int ans = zz;
        int k = zz % int(pow(10, (to_string(zz).length() - 1)));
        k *= 10;
        k += zz / pow(10, (to_string(zz).length() - 1));
        if (z == k) v.pb(ans);
    }

    for (int j: v) 
        cout << j << '\n';
    if (v.size() == 0) 
        cout << "No solution\n";
        

    return 0;
}