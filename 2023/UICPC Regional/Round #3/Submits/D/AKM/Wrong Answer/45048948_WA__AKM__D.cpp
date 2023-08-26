#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> p;
int countDigit(long long n)
{
    if (n / 10 == 0)
        return 1;
    return 1 + countDigit(n / 10);
}

long long digits_sum(long long to_solve)
{
    if (to_solve == 0)
        return 0;

    long long digits_num = floor(int(log10(to_solve)) + 1);
    long long res = 0;
    if (digits_num > 1)
    {
        long long mod = p[digits_num - 1];
        long long tmp = to_solve / mod;
        res = tmp * 45 * (digits_num - 1) * p[digits_num - 2];
        for (int i = 1; i < tmp; i++)
        {
            res += i * mod;
        }
        long long a = to_solve % mod;
        res += (a + 1) * tmp;
        res += digits_sum(a);
    }
    else
    {
        for (int i = 1; i <= to_solve; i++)
            res += i;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long r = 1;
    p.push_back(r);
    for (int i = 1; i <= 15; i++)
    {
        p.push_back(p[i - 1] * 10);
    }

    string s = "999999999999999";
    long long c = floor(int(log10(999999999999999)) + 1);

    cout << c << endl << s.size() << endl;

    int t;
    cin >> t;
    // cout << digits_sum(t);
    for (int i = 0; i < t; i++)
    {
        long long first, last;
        cin >> first >> last;
        long long digits_sum_first, digits_sum_last;

        if (first <= 1)
        {
            digits_sum_first = 0;
        }
        else
        {
            digits_sum_first = digits_sum(first - 1);
        }

        if (last == 0)
        {
            digits_sum_last = 0;
        }
        else
        {
            digits_sum_last = digits_sum(last);
        }

        cout << digits_sum_last - digits_sum_first << endl;
    }
}