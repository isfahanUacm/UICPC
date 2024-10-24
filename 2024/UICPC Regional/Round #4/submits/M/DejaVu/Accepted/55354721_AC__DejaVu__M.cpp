#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d;
    cin >> d;
    if (d == 1)
        cout << 7 << " " << 10 << " " << 13;
    else if (d == 2)
        cout << 3 << " " << 11 << " " << 99;
    else if (d == 97 || d == 98 || d == 99 || d == 100)
        cout << 1 << " " << 2 << " " << 3;
    else
        cout << 98 << " " << 99 << " " << 100;

    return 0;
}