#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

string toBin(int n)
{
    string otp;
    while(n)
    {
        otp.push_back(char('0' + (n&1)));
        n = n >> 1;
    }
//    cout << "otp: " << otp << endl;

    string res;
    for(int i=0; i<8-otp.size(); i++) res.push_back('0');
    for(auto x=otp.rbegin(); x<otp.rend(); x++) res.push_back(*x);

    return res;
}

map<string, int> bintodec = {{"000",7},{"001",6},{"010",5},{"011",4},
                             {"100",3},{"101",2},{"110",1},{"111",0}};


void solve()
{
    int r, k; cin >> r >> k;
    string rule = toBin(r);
    string f; cin >> f;
    vector<int> g; g.push_back(0);
    for(auto x : f)
    {
        if(x == '.') g.push_back(0);
        else g.push_back(1);
    }
    g.push_back(0);
    vector<int> ng(g.size());

    for(int counter=0; counter<k; counter++)
    {
        g[0] = 0;
        g[g.size()] = 0;

        for(int i=1; i<g.size()-1; i++)
        {
            string key;
            key.push_back((g[i-1]==0 ? '0' : '1'));
            key.push_back((g[i]==0 ? '0' : '1'));
            key.push_back((g[i+1]==0 ? '0' : '1'));
//            cout << key << endl;

            ng[i] = int(rule[bintodec[key]] - '0');
        }
        g = ng;

        for(int i=1; i<g.size()-1; i++)
        {
            cout << (g[i] == 0 ? '.' : 'X');
        }
        cout << '\n';
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