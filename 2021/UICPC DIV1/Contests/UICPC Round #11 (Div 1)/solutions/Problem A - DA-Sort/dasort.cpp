#include <bits/stdc++.h>
using namespace std;

int p, n, k, a[1003], sorted[1003];

int main()
{
    cin >> p;
    while (p--){
        cin >> k >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i], sorted[i] = a[i];
        sort(sorted, sorted + n);
        int j = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] == sorted[j])
                j++;
        cout << k << " " << n - j << endl;
    }
    return 0;
}

