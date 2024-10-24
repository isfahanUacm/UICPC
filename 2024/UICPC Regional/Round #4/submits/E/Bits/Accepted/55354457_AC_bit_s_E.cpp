#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s; cin >> s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i]-'A'+'a';
    }
    cout << s << '\n';


    for(int i=0; i<s.size()-1; i++)
    {
        if(s[i] == 's')
        {
            if(s[i+1] == 's')
            {
                for(int j=0; j<s.size(); j++)
                {
                    if(j==i)cout << "B";
                    else if(j==i+1) continue;
                    else cout << s[j];
                }
                cout << "\n";
            }
        }
    }
}


int main(int argc, char *argv[])
{
    solve();

    return 0;
}
