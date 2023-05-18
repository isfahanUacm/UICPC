#include <iostream>
#include <math.h>
using namespace std;

int fact(int n)
{
    int pr = 1;
    for (int i = n; i >= 1; i--)
    {
        pr *= i;
    }
    return pr;
}

int main()
{
    int test_num;
    cin >> test_num;
    int n, m;
    for (int i = 0; i < test_num; i++)
    {
        cin >> n >> m;
        int count = n - m + 1;
        cout << fact(n) / (fact(m) * fact(n - m)) * m / count << endl;
    }
}