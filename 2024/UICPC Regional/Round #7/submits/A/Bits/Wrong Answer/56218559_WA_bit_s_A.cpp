#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const ll maxN = 1e5+5;
const ll INF = 1e9+7;

bool cmp(vector<int> a, vector<int> b){
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}
bool cp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int arr[1000];
void solve()
{
    vector<vector<int>> v(1000,vector<int>(3));
    int n,k;
    cin >> n >> k;
    ll sum = 0;
    for(int i=0; i<n; i++){
        cin >> v[i][0];
        arr[i] = v[i][0];
    }
    for(int i=0; i<n; i++){
        cin >> v[i][1];
        v[i][2] = i;
    }
    bool flag = true;
    while (sum < k && flag) {
        sort(v.begin(),v.begin()+n,cmp);
        flag = false;
        for(int i=n-1; i>=0; i--){
            if(v[i][0]-v[i][1] >= 0){
                v[i][0] -= v[i][1];
                flag = true;
                sum++;
                break;
            }
        }
    }
    if(!flag){
        cout << 0;
        for(int i=1; i<n; i++)
            cout << " 0";
        cout << '\n';
        return;
    }
    sort(v.begin(),v.begin()+n,cp);
    cout << (arr[0]-v[0][0])/v[0][1];
    for(int i=1; i<n; i++){
        cout << " " << (arr[i]-v[i][0])/v[i][1];
    }
    cout << '\n';

}

int main()
{
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}