#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
struct pairs{
    ll s;
    ll time;
    bool r;
};

bool operator < (const pairs& a,const pairs& b){
    if(a.s > b.s){
        return true;
    }
    else {
        if(a.s < b.s)
            return false;
        else {
            {
                if( a.time < b.time)
                    return true;
                else if (a.time > b.time)
                    return false;
                else return a.r;
            }
        }
    }
}



void solve() {
    ll a,b;
    cin>>a>>b;
    if((a&b) == 0){
        cout << -1;
        return;
    }

    ll cpy = a;
    vector<bool> z(32,true);
    int zro = 1 - (cpy & 1);
    z[0] = zro;
    int ind =0;
    while(cpy){
        cpy = cpy >> 1;
        ind++;
        if((cpy & 1) == 0){
            zro ++;
            z[ind] = true;
        }
        else z[ind] = false;
    }

    ll possibility = ind + 1;
    possibility -= zro;

    cpy = b;
    bool hasOdd = false;
   vector<bool> odd(ind+1);
    for(ind ;ind>=0;ind--){
        odd[ind] = (cpy>>ind)&1;
        hasOdd = true;
    }
    cout << pow(2,possibility) - (hasOdd? 1 : 0)<<endl;

    ll num = 0;
    ll tmp =1;
    for(int j =0;j< odd.size();j++){
        num = num | (tmp *(odd[j] ? 1 : 0));
        tmp *= 2;
    }
    ll hlp = 0;
    tmp = 1;
    while(hlp < pow(2,possibility)){
        ll number = 0;
        int index = 0;
        tmp = 1;
        for(int j = 0;j<32;j++){
            if(z[j] == true) {
                tmp *= 2;
                continue;
            }

            number = number | (((hlp >> index++) & 1) * tmp);
            tmp *= 2;
        }
        if(number != num)
            cout << number << ' ';

        hlp++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
        if (t) cout << '\n';
    }
    return 0;
}
