#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct p
{
    double x, y;
};

double dist(p p1, p p2, p p3)
{
    double ans;
    if (p2.x == p1.x)
    {
        ans = abs(p3.x - p1.x);
    }
    else
    {
        double A = (p2.y - p1.y) / (p2.x - p1.x);
        double C = p1.y - (A * p1.x);
        ans = abs(A * p3.x - p3.y + C) / sqrt(A * A + 1);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<p> vc;
    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;
        vc.push_back(p{a, b});
    }

    double mi = 10000000;

    for (int j = 0; j < n; j++)
    {
        double mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, dist(vc[j], vc[(j + 1) % n], vc[i]));
        }
        mi = min(mi, mx);
    }

    printf("%.6lf\n", mi);

    return 0;
}