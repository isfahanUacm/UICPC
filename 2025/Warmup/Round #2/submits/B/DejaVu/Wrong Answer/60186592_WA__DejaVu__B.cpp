#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int xs, ys;
    int xe, ye;
    int xp, yp;
    cin >> xs >> ys >> xe >> ye >> xp >> yp;
    if (xe >= xs && ye >= ys)
    {
        if ((xp >= xe && yp >= ye) || (xp <= xs && yp <= ys))
        {
            cout << 0 << endl;
        }
        else if (xp <= xs && yp >= ye)
        {
            if (xs != xe && ys != ye)
            {
                cout << 1 << endl;
                cout << xe << " " << ys << endl;
            }
            else
                cout << 0 << endl;
        }
        else if (xp >= xe && yp <= ys)
        {
            if (xs != xe && ys != ye)
            {
                cout << 1 << endl;
                cout << xs << " " << ye << endl;
            }
            else
                cout << 0 << endl;
        }
        else
        {
            cout << 3 << endl;
            cout << -1000000 << " " << ys << endl;
            cout << -1000000 << " " << 1000000 << endl;
            cout << xe << " " << 1000000 << endl;
        }
    }
    else if (xe >= xs && ye <= ys)
    {
        if ((xp >= xe && yp <= ye) || (xp <= xs && yp >= ys))
        {
            cout << 0 << endl;
        }
        else if (xp <= xs && yp <= ye)
        {
            if (xs != xe && ys != ye)
            {
                cout << 1 << endl;
                cout << xe << " " << ys << endl;
            }
            else
                cout << 0 << endl;
        }
        else if (xp >= xe && yp >= ys)
        {
            if (xs != xe && ys != ye)
            {
                cout << 1 << endl;
                cout << xs << " " << ye << endl;
            }
            else
                cout << 0 << endl;
        }
        else
        {
            cout << 3 << endl;
            cout << -1000000 << " " << ys << endl;
            cout << -1000000 << " " << -1000000 << endl;
            cout << xe << " " << -1000000 << endl;
        }
    }
    else if (xe <= xs && ye >= ys)
    {
        if ((xp <= xe && yp >= ye) || (xp >= xs && yp <= ys))
        {
            cout << 0 << endl;
        }
        else if (xp >= xs && yp >= ye)
        {
            if (xs != xe && ys != ye)
            {
                cout << 1 << endl;
                cout << xe << " " << ys << endl;
            }
            else
                cout << 0 << endl;
        }
        else if (xp <= xe && yp <= ys)
        {
            if (xs != xe && ys != ye)
            {
                cout << 1 << endl;
                cout << xs << " " << ye << endl;
            }
            else
                cout << 0 << endl;
        }
        else
        {
            cout << 3 << endl;
            cout << 1000000 << " " << ys << endl;
            cout << 1000000 << " " << 1000000 << endl;
            cout << xe << " " << 1000000 << endl;
        }
    }
    else
    {
        if ((xp <= xe && yp <= ye) || (xp >= xs && yp >= ys))
        {
            cout << 0 << endl;
        }
        else if (xp >= xs && yp <= ye)
        {
            if (xs != xe && ys != ye)
            {
                cout << 1 << endl;
                cout << xe << " " << ys << endl;
            }
            else
                cout << 0 << endl;
        }
        else if (xp <= xe && yp >= ys)
        {
            if (xs != xe && ys != ye)
            {
                cout << 1 << endl;
                cout << xs << " " << ye << endl;
            }
            else
                cout << 0 << endl;
        }
        else
        {
            cout << 3 << endl;
            cout << 1000000 << " " << ys << endl;
            cout << 1000000 << " " << -1000000 << endl;
            cout << xe << " " << -1000000 << endl;
        }
    }

    return 0;
}