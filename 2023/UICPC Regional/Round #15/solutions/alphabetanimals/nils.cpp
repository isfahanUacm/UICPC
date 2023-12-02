#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string word;
    cin >> word;
    cin >> n;
    vector<string> words(n);
    int start_with[26] = {0};
    rep(c1,0,n){
        cin >> words[c1];
        start_with[words[c1][0]-'a']++;
    }
    int last = word[word.length()-1]-'a';
    if(start_with[last] == 0){
        cout << "?\n";
        return 0;
    }
    string ans = "";
    rep(c1,0,n){
        if(words[c1][0]-'a' != last)continue;
        if(ans.length() == 0)ans = words[c1];
        int last2 = words[c1][words[c1].length()-1]-'a';
        if(start_with[last2] == 0 || (start_with[last2] == 1 && last == last2)){
            cout << words[c1] << "!\n";
            return 0;
        }
    }
    cout << ans << "\n";

    return 0;
}

