#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, inp;
    cin >> n;
    int zero = 0;
    int one = 0;
    int two = 0;
    int four = 0;
    int eight = 0;
    int sixteen = 0;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        switch (inp) {
            case 0:
                zero++;
                break;
            case 1:
                one++;
                break;
            case 2:
                two++;
                break;
            case 4:
                four++;
                break;
            case 8:
                eight++;
                break;
            case 16:
                sixteen++;
                break;
        }
    }
    long double result = zero*2 + one*1 + two*0.5 + four*0.25 + eight*0.125 + sixteen*0.0625;
    cout << setprecision(6) << fixed << result;
}