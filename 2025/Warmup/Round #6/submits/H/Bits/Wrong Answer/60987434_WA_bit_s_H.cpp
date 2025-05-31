#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n,m ; cin >> n >> m;
    string s = bitset<11>(n).to_string();
    vector<int> OR;
    for(int i = 0 ;i < s.size() ; i ++)
    {
        if(s[i] == '0')
        {
            OR.push_back(i);
        }
    }
    string XOR = bitset<11>(m).to_string();
    for(int i = 0 ; i < XOR.size() ;i++)
    {
        if(XOR[i] == '1')
            if(s[i] == '0') {
                cout << "-1\n";
                return ;
            }
    }
    vector<string> res;
    for(int i = 0 ; i <= n ;i ++)
    {
        string r = bitset<11>(i).to_string();
        if(r == XOR)
            continue;
        bool tr = true ;
        for(int j = 0 ; j < r.size() ; j++)
        {
            if(r[j] == '1')
            {
                if(find(OR.begin(),OR.end(),j) != OR.end())
                {
                    tr = false ;
                }
            }
        }
        if(tr)
            res.push_back(r);
    }
    cout << res.size() << '\n';
    sort(res.begin(),res.end());
    for(int i = 0 ; i < res.size() ; i++)
    {
        int rs = stoi(res[i],nullptr,2);
        cout << rs << " " ;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
    cin >> n;
    while(n--)
        solve();

    return 0;
}