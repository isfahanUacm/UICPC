#include <bits/stdc++.h>
using namespace std;

// DA-Sort

int p, k, n, x;
map<int, vector<int>> ind;

int main(){
    cin >> p;
    while(p--){
        cin >> k >> n;
        ind.clear();
        for(int i = 0; i < n; i++)
            cin >> x, ind[x].push_back(i + 1);
        int ans = 0, cover = 0;
        for(auto p : ind){
            if(p.second.front() > cover){
                ans += p.second.size(), cover = p.second.back();
                continue;
            }
            for(int y : p.second)
                if(y > cover)
                    ans++;
            break;
        }
        cout << k << " " << n - ans << endl;
    }
}