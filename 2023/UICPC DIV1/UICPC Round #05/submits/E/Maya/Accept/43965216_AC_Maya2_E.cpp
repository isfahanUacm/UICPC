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
        int number, mn = 1e9, mnnum = 0, num;
        cin >> number;
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    num = 0;
                    num += i * 10;
                    num += j;
                    num *= 10;
                    num += k;
                    num *= 10;
                    num += k; 
                    num *= 10;
                    num += j;
                    num *= 10;
                    num += i;
                    if (mn > abs(number - num)) {
                        mn = abs(number - num);
                        mnnum = num;
                    }
                }
            }
        }
        cout << mnnum << '\n';
    }

    return 0;
}