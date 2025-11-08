#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    for (int i = 0; i < 99; ++i) {
        int x;
        cin >> x;
    }
    int a;
    cin >> a;

    if (a % 10 == 0) {
        cout << 10 << endl;
    }else
        cout << a % 10 << endl;

    return 0;
}
