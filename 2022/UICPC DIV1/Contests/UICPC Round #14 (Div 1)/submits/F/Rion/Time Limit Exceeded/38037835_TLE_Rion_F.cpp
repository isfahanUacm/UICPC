#include <bits/stdc++.h>
using namespace std;

void reverse_s(int &i, int &j, string &s)
{
    char c;
    for (int k = 0; k <= (j - i) / 2; k++)
    {
        c = s[i + k];
        s[i + k] = s[j - k];
        s[j - k] = c;
    }
}

bool is_valid(int &i, int &j, string s1, string &s2)
{
    reverse_s(i, j, s1);

    return s1 == s2;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int count = 0;

    int l = s1.length();

    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (is_valid(i, j, s1, s2)) count++;
        }
    }

    cout << count;
    return 0;
}