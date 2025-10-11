#include <iostream>

using namespace std;


int main() {
    freopen("army.in","r",stdin);
    int t;
    cin >> t;
    int c = 0;
    while (t--) {
        long long int n;
        cin >> n;
        long long i = 1;
        long long counter = 0;
        while (true) {
            while (n - i * i >= 0) {
                n -= (i * i);
                counter = (i * i);
                i++;
            }
            bool flag = false;
            for (int j = 1; j <= i; ++j) {
                n -= j;
                counter++;
                if (n == 0) {
                    flag = true;
                    break;
                }

                if (n < 0) {
                    n += j;
                    counter--;
                    break;
                }
            }
            if (flag) {
                break;
            }
            for (long long int k = i - 1; k >= 1; k--) {
                if (n == 0) {
                    flag = true;
                    break;
                }

                if (n - k >= 0) {
                    n -= k;
                    counter++;
                }
            }
            if (flag) {
                break;
            }
        }
        c++;
        cout << "Case " << c << ": " << counter << endl;
    }

    return 0;
}
