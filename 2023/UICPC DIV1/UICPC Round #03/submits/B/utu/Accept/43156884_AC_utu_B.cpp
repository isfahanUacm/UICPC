#include <bits/stdc++.h>
using namespace std;

double bibToDec(string str)
{
    double answer = 0;
    for (int i = 2; i < str.size(); i++)
    {
        if (str[i] == '1')
            answer += pow(2, 1 - i);
    }
    return answer;
}

string solve(double a, double b, char ch, double pa, double target, int n)
{
    double c = a + pa * (b - a);
    string sa, sb;

    if (n == 0)
    {
        if (a == target)
        {
            sa = "";
            sa += ch;
            return sa;
        }
        else
        {
            return "";
        }
    }

    if (ch == 'A')
    {
        sa = solve(a, c, 'A', pa, target, n - 1);
        sb = solve(a, c, 'B', pa, target, n - 1);

        if (sa == "" && sb == "")
            return "";
        else if (sa == "")
            return "A" + sb;
        else
            return "A" + sa;
    }
    else
    {
        sa = solve(c, b, 'A', pa, target, n - 1);
        sb = solve(c, b, 'B', pa, target, n - 1);

        if (sa == "" && sb == "")
            return "";
        else if (sa == "")
            return "B" + sb;
        else
            return "B" + sa;
    }
}

int main()
{
    int n;
    double d;

    cin >> n >> d;
    double pa = d / 8;

    string bin;
    cin >> bin;

    double target = bibToDec(bin);
    string sa = solve(0, 1, 'A', pa, target, n);
    string sb = solve(0, 1, 'B', pa, target, n);

    if (sa == "")
        cout << sb.substr(0, sb.size() - 1);
    else
        cout << sa.substr(0, sa.size() - 1);

    return 0;
}