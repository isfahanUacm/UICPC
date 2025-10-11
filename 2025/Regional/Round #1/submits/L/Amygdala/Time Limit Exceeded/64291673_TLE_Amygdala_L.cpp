#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
const int mod = 1e9+7;

string generate(char s, int len, int mul, int add)
{
    string otp; otp.push_back(s);
    len --;
    while(len--)
    {
        int res = (otp.back() - 'a');
        res *= mul;
        res += int(otp.size()) * add;
        res %= 26;
        res += 'a';

        otp.push_back(char(res));
    }
    return otp;
}

bool check(string s1, string s2)
{
    int d = -1;
    for(char a : s1){
//        if(d==s2.size())
//            return false;
        int ind = s2.find(a,d+1);
        if(ind == -1)
            return false;
        d = ind;
//        cout << d << endl;
    }
    return true;
}

void solve(int t)
{
    cout << "Case " << t << ":\n";
    char s; int l, mul, add;
    cin >> s >> l >> mul >> add;
    string word = generate(s, l, mul, add);
    int n; cin >> n;
    while(n--)
    {
        char ss;
        int l2, mul2, add2;
        cin >> ss >> l2 >> mul2 >> add2;
        string spelled = generate(ss, l2, mul2, add2);
        if(check(spelled, word)) cout << "BRAVO\n";
        else cout << "REPEAT\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("mahdi.in", "r", stdin);
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        solve( i+1);
    }

//    cout << check("abc", "dafcghbres");

    return 0;
}