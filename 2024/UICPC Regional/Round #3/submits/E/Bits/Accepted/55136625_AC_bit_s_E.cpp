#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const maxI = 1e5*2;

bool compare(vector<int> v1, vector<int> v2){
    if(v1[0] == v2[0])
        return v1[1] > v2[1];
    else
        return v1[0] > v2[0];
}

pair<int,int> arr[5000];
bool mark[5000];
vector<int> ans(5000);

void solve(){
    vector<vector<int>> s(5000, vector<int>(3));
 int n,m;
 cin >> n >> m;
 for(int i = 0; i<n; i++){
     cin >> arr[i].first;
     arr[i].second = i;
 }
 for(int i=0; i<m; i++)
     cin >> s[i][1];
 for(int i=0; i<m; i++){
     cin >> s[i][0];
     s[i][2] = i+1;
 }
 sort(arr,arr+n);
 sort(s.begin(),s.end(),compare);
 bool f;
 for(int i=n-1; i>=0; i--){
     f = true;
     for(int j=m-1; j>=0; j--){
         if(s[j][1] >= arr[i].first && !mark[j]){
             ans[arr[i].second]=s[j][2];
             mark[j] = 1;
             f = false;
             break;
         }
     }
     if(f){
         cout << "impossible\n";
         return;
     }
 }

 cout << ans[0];
 for(int i=1; i<n; i++)
     cout << ' ' << ans[i];
 return;
}

int main()
{
    solve();
    return 0;
}
