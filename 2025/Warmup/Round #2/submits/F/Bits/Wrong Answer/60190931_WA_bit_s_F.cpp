#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    cint(n); cint(m);
    vector<string> v(n*2);
    for(int i=0; i<n*2-1; i++)
        cin >> v[i];

    ll res = 0;
    vector<string> str;
    vector<int> plus;
    plus.push_back(0);
    str.push_back(v[0]);
    for (int i = 1; i < n * 2 - 1; i += 2) {
        if (v[i] == "*") {
            res = stoi(str[str.size() - 1]);
            res *= stoi(v[i + 1]);
            str[str.size() - 1] = to_string(res);
        } else {
            str.push_back(v[i]);
            str.push_back(v[i + 1]);
            plus.push_back(i);
        }
    }
    res = stoi(str[0]);
    for (int i = 1; i < str.size(); i += 2) {
        if (str[i] == "+") {
            res += stoi(str[i + 1]);
        } else
            res -= stoi(str[i + 1]);
    }
    bool ise = false;
    if (res % 2 == 0) {
        cout << "even\n";
        ise = 1;
    } else cout << "odd\n";

    for(int i = 0 ; i < m ; i ++)
    {
        cint(k); cint(l);
        k = (k-1) * 2;
        int ind = upper_bound(plus.begin(),plus.end(),k) - plus.begin();
        int num = stoi(str[(ind-1)*2]);
        int newnum = (num / stoi(v[k])) * l;
        v[k] = to_string(l);
        if(newnum %2 != num%2)
            ise = !ise;
        if (ise) {
            cout << "even\n";
        } else cout << "odd\n";
    }

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