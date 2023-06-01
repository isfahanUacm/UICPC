#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p, s, m, temp;

    cin >> n >> p >> s;
    bool keep = false;

    for (int i = 0; i < s; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            if (temp == p) keep = true;
        }

        if (keep)
            cout << "KEEP\n";
        else
            cout << "REMOVE\n";
        
        keep = false;
    }

    return 0;
}
