#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
#define pb push_back
#define pf push_front

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string number;
        cin >> number;
        cout << number[0] << number[1] << number[2];
        cout << number[2] << number[1] << number[0];
        cout << '\n';
    }

    return 0;
}