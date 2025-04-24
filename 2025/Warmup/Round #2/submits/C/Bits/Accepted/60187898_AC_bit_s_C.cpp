#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

int f(string s, int l, int r, bool flag)
{
    if(r-l < 2)
        return 1;

    vector<int> mul;
    int c =0;
    int lil = l;
    int res = 0;
    for(int i=l; i<r; i++)
    {
        if(s[i] == '(') c++;
        else c--;

        if(c == 0)
        {
            mul.push_back(f(s, lil+1, i, false));
            if(flag && lil==l && i==r-1){
                res = -1;
            }
            lil = i+1;
        }
    }

    int ans = 1;
    for(auto x : mul)
    {
//        cout << x << ' ';
        ans *= x;
    }
//    cout << endl;

    return ans + 1 + res;
}

void solve()
{

    cint(n);
    string ss; cin >> ss;
    string s = "(";
    s = s + ss;
    s.push_back(')');


    cout << f(s, 0, s.size(), true) - 1;
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