#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const ll maxN = 1e5+5;
const ll INF = 1e9+7;
int arr[1000];
void solve()
{
    vector<vector<int>> v(1000,vector<int>(3));
    int n,k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> v[i][0];
    }
    for(int i=0; i<n; i++){
        cin >> v[i][1];
        v[i][2] = i;
    }
    for(int i=n-1; i>=0; i--){
        if(k==0)
            break;
        int m = v[i][0]/v[i][1];
        if(m > k){
            arr[i] = k;
            k = 0;
        }
        else{
            arr[i] = m;
            k -= m;
        }
    }
    if(k){
        cout << 0;
        for(int i=1; i<n; i++)
            cout << " 0";
        cout << '\n';
        return;
    }
    cout << arr[0];
    for(int i=1; i<n; i++){
        cout << " " << arr[i];
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