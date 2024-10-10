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

void solve(){
    char arr[100];
    memset(arr,0,sizeof arr);
    int q,m;
    cin >> q >> m;
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
        if(arr[i] == 0){
            if(adj[i].size() == 3)
                cout << ans(i) << ' ';
            else
                cout << "? ";
        }
        else
            cout << arr[i] << ' ';
        adj[i].clear();
    }
    cout << '\n';
}

int main()
{
    int t; cin >> t;
    while(t--)
    solve();
}
