#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int b;
    double p;
    double bpm;
    double diff;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        cin >> p;

        bpm = (60 * b) / p;
        diff = 60 / p;

        cout << setprecision(4) << fixed << (bpm - diff) << ' ' << bpm << ' ' << (bpm + diff) << '\n';
    }
    return 0;
}