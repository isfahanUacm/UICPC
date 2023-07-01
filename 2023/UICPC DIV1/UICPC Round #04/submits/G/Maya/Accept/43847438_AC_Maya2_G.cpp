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
    string s1, s2;
    cin >> s1 >> s2;
    if (n % 2 == 0 && s1 == s2) {
        cout << "Deletion succeeded\n";
        return 0;
    }
    else if (n % 2 == 1) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == s2[i]) {
                cout << "Deletion failed\n";
                return 0;
            }
        }
    }
    else {
        cout << "Deletion failed\n";
        return 0;
    }

    cout << "Deletion succeeded\n";

    return 0;
}