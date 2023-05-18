#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<unsigned long long> input;
    vector<unsigned long long> squareSums;
    vector<unsigned long long> reverseSums;
    int s = 0;
    for (int i = 0; i < n; i++) {
        unsigned long long a;
        cin >> a;
        input.push_back(a);
        unsigned long long aa = a * a;
        if (i == 0) {
            squareSums.push_back(aa);
        } else {
            squareSums.push_back(aa + squareSums.back());
        }
        s += a;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            reverseSums.push_back(s);
        } else {
            reverseSums.push_back(reverseSums.back() - input[i-1]);
        }
    }

    unsigned long long max = 0;

    for (int i = 0; i < n - 1; i++) {
        unsigned long long s = squareSums[i] * reverseSums[i + 1];
        if (s > max) {
            max = s;
        }
    }

    cout << max << endl;

    return 0;
}
