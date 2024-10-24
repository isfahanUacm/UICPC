#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    int d = to_string(n).size();
    int k=-1;
    for(char c='0'; c<'9'; c++)
    {
        string s1, s2;
        for(int i=0; i<d; i++)
        {
            s1.push_back(c);
            s2.push_back(c+1);
        }

//        cout << "s1: " << s1 << "  s2: " << s2 << "  k: " << k << "\n\n";
        if(n>=stoi(s1) && n<stoi(s2))
        {
//            cout << "YYYEEESSS\n\n\n";
            k = c - '0';
            break;
        }
    }
    if(k==-1) k=9;

//    cout << "dbg k: " << k << endl;

    cout << (k*d) + (10-k)*(d-1);
}


int main()
{
    solve();

    return 0;
}
