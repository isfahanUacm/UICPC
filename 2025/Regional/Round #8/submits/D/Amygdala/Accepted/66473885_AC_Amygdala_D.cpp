#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';


void solve(int n)
{
    string s, tar;
    cin >> s;
    cin >> tar;

    int a=0, b=0;
    for(auto x : s) (x=='a' ? a++ : b++);

    int tar_a=0, tar_b=0;
    for(auto x : tar) (x=='a' ? tar_a++ : tar_b++);

    if(tar_a != a || tar_b != b)
    {
        cout << "no\n";
        return;
    }

    cout << "yes\n";
    int first_b = 0;
    for(auto x : s){if(x == 'b') first_b++; else break;}
    for(int i=0; i<b - first_b; i++) cout << 'A';

    vector<pInt> v;
    int temp = 0;
    for(int i=0; i<tar.size(); i++)
    {
        if(tar[i] == 'b') temp ++;
        else if(temp)
        {
            v.emplace_back(i-1, temp);
            temp = 0;
        }
    }
    if(temp)
    {
        v.emplace_back(tar.size()-1, temp);
        temp = 0;
    }

//    for(auto x : v) cout << x.first << ',' << x.second << ' '; cout << endl;
//    cout << first_b << endl;

    while(!v.empty())
    {
        pInt last = v.back();
        v.pop_back();

        if(last.first >= b)
        {
            for(int i=0; i<last.first-b+1; i++) cout << 'B';
            b -= last.second;
            for(int i=0; i<b; i++) cout << 'A';
        }
        else break;
    }

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t)
    {
        cin >> t;
        if(!t) break;
        solve(t);
    }

    return 0;
}