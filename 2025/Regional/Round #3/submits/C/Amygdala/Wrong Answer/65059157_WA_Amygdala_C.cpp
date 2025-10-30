#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back

const int N = 200;
double a[N] , mx[N] , mn[N];
string s[N];


void solve()
{
    int n;  cin >>n;
    string s; cin >> s;
    vector<char> num,chr;
    int plus = 0, mul = 0, o = 0, c=0,z=0;
    for(char a : s){
        if(a == '(')
            o++;
        else if(a == ')')
            c++;
        else if(a == '*')
            mul++;
        else if(a == '+')
            plus++;
        else if(a >= '0' && a<='9')
            num.push_back(a);
        else if(a == '!')
            z++;
        else
            chr.push_back(a);
    }
    if(o!=c || o > min(mul,plus) || mul+plus >= num.size()+chr.size() || (z==1 || z>2)){
        cout << "impossible\n";
        return;
    }
    sort(num.rbegin(),num.rend());
    vector<string> var;
    int sz = num.size() + chr.size() - (mul+plus+1);
    for(int i=0; i<=mul+plus; i++){
        if(!num.empty()) {
            var.push_back(to_string(num.back()-'0'));
            num.pop_back();
        }
        else{
            string s={ chr.back()};
            var.push_back(s);
            chr.pop_back();
        }
    }
    int i = mul+plus;
    if(sz > 0){
        string b = "";
        while(!num.empty()){
            b = num.back() + b;
            num.pop_back();
        }
        b += var[i];
        while(!chr.empty()){
            b = chr.back() + b;
            chr.pop_back();
        }
        var[i] = b;
    }
    if(var[i][0] == '0'  && var[i].length()>1){
        cout << "impossible\n";
        return;
    }
    vector<string> v;
    while(o--)
        v.push_back("(");

    v.push_back(var.back());
    var.pop_back();
    while(c--){
        v.push_back("+");
        v.push_back(var.back());
        var.pop_back();
        v.push_back(")*");
        v.push_back(var.back());
        var.pop_back();
        mul--;
        plus--;
    }

    cout << "possible\n";
    if(z)
        cout << '!';
    for(string a : v)
        cout << a;
    if(z)
        cout << '!';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<20; i++) cout << i << ':' << is_prime(i) << endl;
    return 0;
}