#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define vi vector <int>
#define all(x) x.begin(),x.end()

const int N = 1e6+9 , INF = 1e18 ;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    cin >> T;
    while(T--) {
        int n;  cin >> n;
        vector<pair<int,int>> l(n);
        set<pair<int,int>> c;
        vector<int> v(n);
        set<int> mark;
        for(int i=0; i<n; i++) {
            int j;  cin >> j;
            l[i] = {j,i};
        }
        for(int i=0; i<n; i++){
            int j;  cin >> j;
            c.insert({j,i});
            v[i] = j;
        }
        sort(l.begin(), l.end());

        vector<vector<int>> ans(n,vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0;j<n; j++)
                ans[i][j] = 0;
        }
        int i=0;
        for(; i<n; i++){
            int ind = l[i].second;
            auto num = c.lower_bound({l[i].first,0});
            if(num == c.end())
                break;
            ans[ind][(*num).second] = l[i].first;
            if((*num).first > l[i].first) {
                c.insert({(*num).first - l[i].first, (*num).second});
                mark.insert((*num).second);
                v[(*num).second] = (*num).first - l[i].first;
            }
            else{
                mark.erase((*num).second);
            }
            c.erase(num);

        }
        for(; i<n; i++){
            int ind = l[i].second;
            int cnt = l[i].first;
            while(!mark.empty()){
                int j = *mark.begin();
                c.erase({v[j],j});
                if(cnt > v[j]){
                    cnt-=v[j];
                    mark.erase(j);
                    ans[ind][j] = v[j];
                }
                else{
                    ans[ind][j] = cnt;
                    if(v[j] > cnt){
                        v[j]-=cnt;
                    }
                    cnt = 0;
                    break;
                }
            }
            if(cnt==0) continue;
            while(!c.empty()){
                pair<int,int> num = *c.rbegin();
                if(cnt > num.first){
                    ans[ind][num.second] = num.first;
                    cnt-=num.first;
                }
                else{
                    ans[ind][num.second] = cnt;
                    if(num.first > cnt){
                        c.insert({num.first-cnt,num.second});
                    }
                    cnt = 0;
                    break;
                }
                c.erase(num);
            }
        }
        for(int k=0; k<n; k++){
            for(int j=0;j<n; j++)
                cout << ans[k][j] << " ";
            cout << '\n';
        }
        for(int k=0; k<n; k++){
            cout << l[k].second+1 << " ";
        }
        cout << '\n';
    }




    return 0;

}
