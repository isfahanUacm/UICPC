#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    long answer = 0;
    cin >> n;
    if (n % 2 == 0)
    {
        answer = (n / 2) * (n / 2 + 1);
    }
    else
    {
        answer = (n / 2 + 1) * (n / 2 + 1);
    }
    cout << answer;
}