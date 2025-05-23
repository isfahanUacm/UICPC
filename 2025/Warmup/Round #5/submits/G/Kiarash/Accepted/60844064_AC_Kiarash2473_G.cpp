#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;
    if (x <= 12 && x >= 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}