#include <bits/stdc++.h>
using namespace std;

set<char> adj[100];
char ans(int i){
    adj[i].insert('A');
    if(adj[i].size() == 4)
        return 'A';
    adj[i].insert('B');
    if(adj[i].size() == 4)
        return 'B';
    adj[i].insert('C');
    if(adj[i].size() == 4)
        return 'C';
    return 'D';
}
char arr[100+5];

void solve(){

    memset(arr,0,sizeof arr);
    int q,m;
    cin >> q >> m;
    for(int i = 0 ; i < q ; i ++)
    {
        adj[i].clear();
    }
    for(int i=0; i<m; i++){
        for(int j =0; j<q; j++){
            char t, fl;
            cin >> t >> fl;
            if(fl == 'F'){
                adj[j].insert(t);
            }
            else
                arr[j] = t;
        }
    }
    for(int i = 0; i<q; i++){
        if(i)
            cout << ' ';
        if(arr[i] == 0){
            if(adj[i].size() == 3)
                cout << ans(i);
            else
                cout << '?';
        }
        else
            cout << arr[i];

    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t; cin >> t;
    for(int i = 0 ; i < t ; i ++)
        solve();
}
