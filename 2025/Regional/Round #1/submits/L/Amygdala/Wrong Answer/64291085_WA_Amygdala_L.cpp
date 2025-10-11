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
    if(s2.size() < s1.size()) return false;
    int p1 = 0, p2 = 0;
    for(p2; p2<s2.size() && p1<s1.size(); p2++)
    {
        if(s1[p1] == s2[p2]) p1++;
    }
    if(p1 == s1.size()) return true;
    return false;
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

    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        solve( i+1);
    }

//    cout << generate('d', 5, 31, 12);

    return 0;
}