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
int a[N];

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int sum= 0;
    int min =0;
    int tmp;
    for(int i =0 ; i < n;i++){
        cin >> tmp;
        sum += tmp;

        if( sum < min)
        min = sum;


    }

    cout << (min < 0 ? -min : 0);

}

