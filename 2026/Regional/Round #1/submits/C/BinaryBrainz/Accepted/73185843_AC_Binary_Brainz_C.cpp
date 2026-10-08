#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    string a,b,c;
    cin >> a >> b >> c;
    map<char , int> m, ansm;
    vi v(10);
    for(char &x : a){
        m[x] = 1;
    }
    for(char &x : b){
        m[x] = 1;
    }
    for(char &x : c){
        m[x] = 1;
    }

    auto num = [&](string str){

        ll p = 1;
        ll number = 0;

        for(int i = str.length()-1; i >= 0; i--){
            number += m[str[i]] * p;
            p *= 10;
        }

        return number;
    };

    auto validate = [&](){
        if(num(a) + num(b) == num(c))
            return true;

        return false;
    };

    ll cnt = 0;
    auto f = [&](map<char , int>::iterator it, auto && self) -> void{

        if(it == m.end() || it->first == '\0'){
            if(validate()){
                if(ansm.size() == 0){
                    for(auto &itr : m){
                        ansm[itr.first] = itr.second;
                    }
                }
                cnt++;
            }
            return;
        }

        for (int i = 0; i < 10; ++i) {
            if(v[i]){
                continue;
            }
            if(i == 0 && (a[0] == it->first || b[0] == it->first || c[0] == it->first)){
                continue;
            }
            v[i] = true;
            it->second = i;
            self(next(it),self);
            v[i] = false;
        }
    };

    f(m.begin(),f);

    cout << cnt <<'\n';
    if(cnt){
        m = ansm;
        cout << num(a) <<'\n';
        cout << num(b) <<'\n';
        cout << num(c) <<'\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}