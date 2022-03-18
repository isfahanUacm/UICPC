#include<bits/stdc++.h>
using namespace std;

// Crazy Driver

int n, t[100003]; 
long long int c[100003];

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++)
        cin >> t[i];
    long long int ans = 0, currm = LLONG_MAX;
    int T = 0;
    for(int gate = 2; gate <= n; gate++){
        T++, ans += c[gate], currm = min(currm, c[gate]);
        if(t[gate] > T){
            int waste = t[gate] - T + (t[gate] - T) % 2;
            T += waste, ans += currm * waste;
        }
    }
    cout << ans << endl;
}