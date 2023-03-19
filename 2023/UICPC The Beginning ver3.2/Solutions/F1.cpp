#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<double, double>> points;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;

        points.push_back(make_pair(x, y));
    }

    int idx1 = 0, idx2 = 0;
    double maxDis = 0;

    for (int i = 0; i < n - 1; i++)
    {
        double dist = sqrt(pow((points[i].second - points[i + 1].second), 2) + pow((points[i].first - points[i + 1].first), 2));
        if (dist > maxDis)
        {
            maxDis = dist;
            idx1 = i;
            idx2 = i + 1;
        }
    }

    double dist = sqrt(pow((points[0].second - points[n - 1].second), 2) + pow((points[0].first - points[n - 1].first), 2));
    if (dist > maxDis)
    {
        maxDis = dist;
        idx1 = n - 1;
        idx2 = 0;
    }

    bool flag = true;

    if (points[idx2].first == points[idx1].first)
        flag = false;

    if (flag)
    {
        double m = (points[idx2].second - points[idx1].second) / (points[idx2].first - points[idx1].first);
        double b = points[idx1].second - m * points[idx1].first;

        double dMax = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == idx1 || i == idx2)
                continue;

            double d = abs((points[i].second + (-1 * m) * points[i].first - b));
            d /= sqrt(1 + m * m);

            dMax = max(dMax, d);
        }
        cout << setprecision(8) << fixed << showpoint << dMax << "\n";
    }
    else
    {
        double dMax = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == idx1 || i == idx2)
                continue;

            double d = abs((points[i].first - points[idx1].first));
            dMax = max(dMax, d);
        }
        cout << setprecision(8) << fixed << showpoint << dMax << "\n";
    }

    return 0;
}
