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

    int l = s1.length();

    for (int i = 0; i < l - 1; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (is_valid(i, j, s1, s2)) count++;
        }
    }

    cout << count;
    return 0;
}