#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string s;
    int curr_i;
    int prev_i;
    int diff_i;
    double circum = 2 * 30 * M_PI;
    double t_each_letter = (circum / 15) / 28;
    double t_total = 1;

    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        t_total = 1;

        if (s[0] == ' ')
            prev_i = 26;
        else if (s[0] == '\'')
            prev_i = 27;
        else
            prev_i = s[0] - 'A';

        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] == ' ')
                curr_i = 26;
            else if (s[j] == '\'')
                curr_i = 27;
            else
                curr_i = s[j] - 'A';

            diff_i = (int)abs(curr_i - prev_i);
            if (diff_i > 14)
                diff_i = 28 - diff_i;

            // cout << "character:" << s[j] << '\n';
            // cout << "prev_i:" << prev_i << " cur_i:" << curr_i << " diff_i: " << diff_i << '\n';

            t_total += diff_i * t_each_letter;
            t_total += 1;
            prev_i = curr_i;
        }

        cout << fixed << setprecision(10) << t_total << '\n';
    }
    return 0;
}