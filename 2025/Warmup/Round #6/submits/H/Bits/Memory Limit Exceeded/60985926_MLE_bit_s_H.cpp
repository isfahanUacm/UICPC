#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n; cin >> n;
    cint(k);
    int n_cpy=n, k_cpy=k;

    string n_bin, k_bin, temp;
    while(n_cpy)
    {
        temp.push_back('0' + n_cpy%2);
        n_cpy = n_cpy >> 1;
    }
    for(auto x=temp.rbegin(); x<temp.rend(); x++) n_bin.push_back(*x);
    temp = "";
    while(k_cpy)
    {
        temp.push_back('0' + k_cpy%2);
        k_cpy = k_cpy >> 1;
    }
    for(int i=0; i<n_bin.size()-temp.size(); i++) k_bin.push_back('0');
    for(auto x=temp.rbegin(); x<temp.rend(); x++) k_bin.push_back(*x);

//    cout << k_bin << ' ' << n_bin << endl;///debug

    for(int i=0; i<n_bin.size(); i++)
    {
        if(n_bin[i] == '0')
            if(k_bin[i] != '0')
            {
                cout << "-1\n";
                return;
            }
    }

    string k2;
    string mp;
    temp = "";
    for(int i=0; i<n_bin.size(); i++)
    {
        if(n_bin[i] != '0')
        {
            k2.push_back(k_bin[i]);
            mp.push_back('1');
            temp.push_back('0');
        }
        else mp.push_back('.');
    }

    int ans = 1;
    for(int i=0; i<k2.size(); i++) ans *=2;
    cout << ans-1 << '\n';

    while(true)
    {
        if(temp != k2)
        {
            string strtoprint;
            int index = 0;
            for (int i = 0; i < mp.size(); i++) {
                if (mp[i] == '.')
                    strtoprint.push_back('0');
                else strtoprint.push_back(temp[index++]);
            }

        cout << stoi(strtoprint, nullptr, 2) << ' ';
//            cout << strtoprint << ' ';
        }

        bool flag = false;
        for(auto x=temp.rbegin(); x<temp.rend(); x++)
        {
            if(*x == '0')
            {
                *x = '1';
                flag = true;
                break;
            }
            else
            {
                *x = '0';
            }
        }
        if(!flag)
            break;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
    cin >> n;
    while(n--)
        solve();

    return 0;
}