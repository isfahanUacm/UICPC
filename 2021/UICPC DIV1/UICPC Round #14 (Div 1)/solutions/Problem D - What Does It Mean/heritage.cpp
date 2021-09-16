#include <bits/stdc++.h>
using namespace std;

// What Does It Mean

#define num long long int

map<string, num> memo;
int n;
pair<string, num> dict[1003];

num mod = 1000000007;

num dp(string str){
    if(str == "")
        return 1;
    if(memo.find(str) != memo.end())
        return memo[str];
    num ans = 0;
    for(int i = 0; i < n; i++){
        auto misPoint = mismatch(dict[i].first.begin(), dict[i].first.end(), str.begin(), str.end()).first;
        bool isPrefix =  misPoint == dict[i].first.end();
        if(isPrefix){
            num subp = (dp(str.substr(misPoint-dict[i].first.begin())) * dict[i].second) % mod;
            ans = (ans + subp) % mod;
        }
    }
    return memo[str] = ans;
}

int main(){
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> dict[i].first >> dict[i].second;
    cout << dp(s) << endl;
}