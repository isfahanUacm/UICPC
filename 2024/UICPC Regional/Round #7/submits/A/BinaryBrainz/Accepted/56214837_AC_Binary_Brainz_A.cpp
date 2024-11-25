#include <iostream>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main()
{
    int n;
    long int k;
    cin >> n >> k;

    ull sum = 0;

    ll* a = new ll[n];
    ll* b = new ll[n];
    ll* c = new ll[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];

        c[i] = (a[i] / b[i]);
        sum += c[i];
    }

    ll free = sum - k;

    if (free < 0) {
        for (int i = 0; i < n; i++) {
            cout << 0;
            if (i != n - 1)
                cout << ' ';
        }
        return 0;
    }
    
    int i = 0;

    for (i; (i < n) && (free > 0); i++) {
        
        ll tmp = c[i];
        c[i] -= free;
        if (c[i] < 0)
            c[i] = 0;
        
        free -= tmp;

        cout << c[i];
        if (i != n - 1)
            cout << ' ';
    }
    for (i; i < n; i++) {
        cout << c[i];

        if (i != n - 1)
            cout << ' ';
    }

    return 0;
}