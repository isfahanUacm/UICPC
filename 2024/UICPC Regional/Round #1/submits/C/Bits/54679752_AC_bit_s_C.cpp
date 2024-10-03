#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> v(n, 0);

    for(int i=0; i<n; i++)
    {
        if(s[i] == '1')
        {
            v[i] = 1;
            v[i+1] = 1;
            v[i+2] = 1;
        }
    }

    int counter = 0;
    for(int i=0; i<n; i++)
    {
        if(v[i] == 1)
            counter ++;
    }

    cout << counter;
}

int main() {
    cin.tie(nullptr);

    solve();

    return 0;
}
