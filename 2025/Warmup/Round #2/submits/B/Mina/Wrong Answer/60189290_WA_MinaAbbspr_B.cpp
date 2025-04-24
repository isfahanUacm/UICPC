#include <bits/stdc++.h>

#define input(n) long long n; cin >> n
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define Endl cout << endl
#define For(i , n) for(int i = 0 ; i < n ; i ++)
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(v) v.begin(),v.end()

using namespace std;

void Main() {
    input(xi);
    input(yi);
    input(xt);
    input(yt);
    input(xp);
    input(yp);
    cout << 1;
    Endl;
    cout << xp - 1 << " " << yp + 1;
    Endl;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    //cin >> test;
    for(int i = 0 ; i < test ; i ++){
        Main();
    }

    return 0;
}