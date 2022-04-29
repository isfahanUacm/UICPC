#include <bits/stdc++.h>
using namespace std;

int n, items[153];
string bins;

map<char, int> mp{
    {'A', 0},
    {'E', 1},
    {'I', 2},
    {'O', 3},
    {'U', 4}
};

string comp = "AEIOU";

inline int repl(int i, char c){
    if(bins[i] == c)
        return 0;
    return items[i];
}

int req[5 + 3];
int msum[35];
int dp[153][35];

int cdp(int i, int mask){
    if(dp[i][mask] != -1)
        return dp[i][mask];
    if(i == n)
        return dp[i][mask] = 0;
    int ans = INT_MAX;
    if(msum[mask] <= n - i - 1)
        ans = min(ans, repl(i, 'X') + cdp(i+1, mask));
    for(int b = 0; b < 5; b++)
        if(mask & (1 << b)){
            int cost = 0;
            for(int j = 0; j < req[b]; j++)
                cost += repl(i + j, comp[b]);
            ans = min(ans, cost + cdp(i + req[b], mask - (1 << b)));
        }
    return dp[i][mask] = ans;
}

int main(){
    cin >> bins;
    n = bins.size();
    for(int i = 0; i < n; i++)
        if(bins[i] != 'X')
            req[mp[bins[i]]]++;
    for(int i = 0; i < n; i++)
        cin >> items[i];
    int d, x;
    cin >> d;
    while(d--){
        cin >> x, x--;
        req[mp[bins[x]]]--;
        bins[x] = 'X';
        items[x] = 0;
    }
    string s;
    cin >> s;
    if(s != "X")
        for(char c : s)
            req[mp[c]]++;
    for(int mask = 0; mask < 32; mask++)
        for(int b = 0; b < 5; b++)
            if(mask & (1 << b))
                msum[mask] += req[b];
    for(int i = 0; i < 153; i++)
        for(int j = 0; j < 35; j++)
            dp[i][j] = -1;
    int mask = 0;
    for(int i = 0; i < 5; i++)
        if(req[i])
            mask += 1 << i;
    cout << cdp(0, mask) << endl;
}