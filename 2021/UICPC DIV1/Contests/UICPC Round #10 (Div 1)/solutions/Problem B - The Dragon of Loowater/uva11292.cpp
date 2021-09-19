#include <bits/stdc++.h>
using namespace std;

// The Dragon of Loowater

#define lli long long int

int n, m;
lli ans;
vector<lli> heads;
vector<lli> knights;

int main(){
    while(11292){
        cin >> n >> m;
        if(n + m == 0)
            break;
        heads.clear();
        knights.clear();
        for(int i = 0; i < n; i++){
            cin >> ans;
            heads.push_back(ans);
        }
        for(int i = 0; i < m; i++){
            cin >> ans;
            knights.push_back(ans);
        }
        if(n > m){
            cout << "Loowater is doomed!" << endl;
            continue;
        }
        ans = 0;
        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());
        auto it = knights.begin();
        for(int head : heads){
            it = lower_bound(it, knights.end(), head);
            if(it == knights.end()){
                ans = -1;
                break;
            }
            ans += *it;
            it = next(it);
        }
        if(ans == -1)
            cout << "Loowater is doomed!" << endl;
        else 
            cout << ans << endl;
    }
}