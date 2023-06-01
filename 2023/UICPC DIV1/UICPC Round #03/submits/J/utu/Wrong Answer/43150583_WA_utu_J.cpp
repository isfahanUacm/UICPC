#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, p;
    cin >> n >> l >> p;

    int passenger;
    int cars[n] = {};

    int l2 = l / 2;
    int diff;
    int max_diff = 0;
    int wagon_num;
    int max_wagon = 0;

    for (int i = 0; i < p; i++)
    {
        cin >> passenger;

        diff = abs((passenger % l) - l2);
        if (diff > max_diff) max_diff = diff;

        wagon_num = passenger / l;

        cars[wagon_num]++;
        if (cars[wagon_num] > max_wagon) max_wagon = cars[wagon_num];
    }

    cout << max_diff << '\n';
    cout << max_wagon << '\n';

    return 0;
}