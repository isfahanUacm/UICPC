#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const maxI = 1e5*2;
void solve(){
    vector<int> v;
    int n; cin >> n;
    for(int i=0; i<n; i++)
    {
        int x;  cin >>x;
        v.push_back(x);
    }
    int m; cin >> m;
    vector<int> mod;
    for(int i=0; i<n; i++)
    {
        mod.push_back(m % v[i]);
    }
    int i_min = 0;
    for(int i=0; i<n; i++)
    {
        if(mod[i] < mod[i_min])
            i_min = i;
    }
    cout << v[i_min];

 return;
}

int main()
{
    solve();
    return 0;
}
