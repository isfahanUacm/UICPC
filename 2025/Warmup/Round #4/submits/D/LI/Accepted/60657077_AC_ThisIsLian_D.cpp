#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define vi vector <int>

const int N = 2e5+9 , INF = 2e9;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    int a , b , c , d;
    cin >> n >> a >> b >> c >> d;
    if(a==c){
        cout << d-b;
        return 0;
    }
    cout << (n-b-1)+((c-a-1)*n)+(d+1)+(c-a);
}


