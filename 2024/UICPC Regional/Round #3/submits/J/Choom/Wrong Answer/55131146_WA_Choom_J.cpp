#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int main() {
    int t;
    cin >> t;

    double n[t], sum = 0;
    for (int i = 0; i < t; i++) {
        cin >> n[i];
        if (n[i] == 0) sum += 2;
        else sum = sum + (1 / n[i]);
    }

    string str = to_string(sum);
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            cnt = str.length() - 1 - i;
            break;
        }
    }

    if (cnt > 6) {
        printf("%.6f", sum);
    } else {
        cout << sum;
    }

    return 0;
}
