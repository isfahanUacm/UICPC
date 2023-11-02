#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    double pass[500];
    char d[20];
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> d >> pass[i];

    sort(pass, pass+n);


    double lat = 0, pre = 0;
    for (int i = n-1; i >= 0; --i) {
        lat += (1-pre);
        pre += pass[i];
    }

    cout.setf(ios::fixed);
    cout.precision(4);
    cout << lat << endl;

    return 0;
}
