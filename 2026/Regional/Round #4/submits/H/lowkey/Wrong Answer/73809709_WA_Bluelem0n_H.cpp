
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n; 
        cin >> n;
        int extra = 0;
        for (int j = 0;  j< n; j++)
        {
            long long a;
            cin >> a;
            if (a != 1) {
                extra++;
            }
        }
        if (extra==0)
        {
            cout << 0 << endl;
        }
        else if (extra == 1) {
            cout << 1 <<endl;
        }
        else
        {
            cout << 2<< endl;
        }
    }
}

