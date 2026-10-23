#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;

    while (test--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int best = 0;  
        int cur = 0;   

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && a[i] - a[i - 1] > 1)
                cur = 0;       
            cur++;             
            best = max(best, cur);
        }

        cout << n - best << '\n';
    }

    return 0;
}