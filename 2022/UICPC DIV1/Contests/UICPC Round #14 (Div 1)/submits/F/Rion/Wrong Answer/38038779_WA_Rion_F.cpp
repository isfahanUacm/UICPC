#include <bits/stdc++.h>
using namespace std;

bool is_valid(int &i, int &j, string s1, string &s2)
{
    char c;
    for (int k = 0; k <= (j - i) / 2; k++)
    {
        c = s1[i + k];
        s1[i + k] = s1[j - k];
        s1[j - k] = c;

        if (s1[i + k] != s2[i + k]) return false;
        if (s1[j - k] != s2[j - k]) return false;
    }

    return s1 == s2;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int count = 0;

    int len = s1.length();
    int l = 0, r = len - 1;
    while (l <= r)
    {
        if (s1[l] != s2[l] && s1[r] != s2[r]) break;

        if (s1[l] == s2[l]) l++;
        if (s1[r] == s2[r]) r--;
    }

    while (l <= r)
    {
        if (is_valid(l, r, s1, s2))
        {
            count++;

            if (l > 1 && r < len - 1)
            {
                l--;
                r++;
            }
            else
            {
                break;
            }
        }
        else
            break;
    }

    cout << count;
    return 0;
}