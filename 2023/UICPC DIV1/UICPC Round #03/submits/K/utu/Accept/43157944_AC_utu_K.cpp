#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string temp;

    double vac_cnt = 0;
    double ctl_cnt = 0;

    int vac[] = {0, 0, 0};
    int ctl[] = {0, 0, 0};

    for (int i = 0; i < n; i++)
    {
        cin >> temp;

        if (temp[0] == 'Y')
        {
            vac_cnt++;

            for (int j = 1; j < 4; j++)
                if (temp[j] == 'Y') vac[j - 1]++;
        }
        else
        {
            ctl_cnt++;

            for (int j = 1; j < 4; j++)
                if (temp[j] == 'Y') ctl[j - 1]++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        double vac_per = vac[i] / vac_cnt;
        double ctl_per = ctl[i] / ctl_cnt;

        double diff = ctl_per - vac_per;
        if (diff <= 0)
            cout << "Not Effective" << '\n';
        else
        {
            cout << setprecision(5) << fixed;
            cout << (diff / ctl_per) * 100 << '\n';
        }
    }

    return 0;
}