#include <bits/stdc++.h>
using namespace std;
string p[13];
map<string, int> mp;
vector<vector<int>> v;
bool conflict[13][13];
int main()
{
    int n, m;
    string a, b;
    while(cin>>n){
        mp.clear();
        v.clear();
        for (int i = 0; i < 13; ++i)
            for (int j = 0; j < 13; ++j)
                conflict[i][j] = false;
        for (int i = 0; i < n; ++i)
            cin>>p[i];
        sort(p, p+n);
        for (int i = 0; i < n; ++i)
            mp[p[i]] = i;
        cin>>m;
        for (int i = 0; i < m; ++i)
            cin>>a>>b, conflict[mp[a]][mp[b]] = true, conflict[mp[b]][mp[a]] = true;
        int arr[n];
        for (int i = 0; i < n; ++i)
            arr[i]=i;
        bool flag = true;
        do{
            flag = true;
            for (int i = 0; i< n-1; ++i)
                if(conflict[arr[i]][arr[i+1]]){
                    flag = false;
                    break;
                }
            if(flag){
                vector<int> neww;
                for (int i = 0; i < n; ++i)
                    neww.push_back(arr[i]);
                v.push_back(neww);
            }
        }while(next_permutation(arr, arr+n));
        if(v.empty())
            cout<<"You all need therapy."<<endl;
        else{
            sort(v.begin(), v.end());
            for (int i=0; i<v[0].size(); i++) {
                cout<<p[v[0][i]]<<((i!=v[0].size()-1)?' ':'\n');
            }
        }
        
    }
    return 0;
}

