#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int tmp = ceil(log2(n));
    int line = tmp * 2 + 2;
    cout << line << endl;
    for (int i = 0; i < 2 * tmp; i += 2)
    {
        cout << "B" << i + 1 << "  = B" << i << " << " << pow(2, i / 2) << endl;
        cout << "B" << i + 2 << "  = B" << i << " | B" << i + 1 << endl;
    }

    cout << "B" << tmp * 2 + 1 << "  = B" << tmp * 2 << " << " << 1 << endl;
    cout << "B" << tmp * 2 + 2 << "  = B" << tmp * 2 << " ^ B" << tmp * 2 + 1 << endl;
    return 0;
}