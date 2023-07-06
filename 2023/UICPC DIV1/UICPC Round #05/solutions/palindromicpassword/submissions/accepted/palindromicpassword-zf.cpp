#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        int best = 0;
        for (int i = 0; i <= 999; ++i) {
            int num = 0, ii = i;
            for (int j = 0; j < 3; ++j, ii /= 10) num = (num*10)+(ii%10);
            num += i*1000;

            if (abs(best-x) > abs(num-x)) best = num;
        }
        cout << best << endl;
    }
    return 0;
}
