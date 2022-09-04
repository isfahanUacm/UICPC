#include <bits/stdc++.h>
using namespace std;

bool is_valid(int& i, int& j, string s1, string& s2)
{
    char c;
    for (int k = i; k <= j / 2; k++)
    {
        c = s1[k];
        s1[k] = s1[j - k + 1];
        s1[j - k + 1] = c;
    }

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