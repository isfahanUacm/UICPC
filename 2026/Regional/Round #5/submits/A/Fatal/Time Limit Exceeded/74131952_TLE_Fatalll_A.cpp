#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    int res[m] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j <arr[i]; j++)
        {
                res[j] += arr[i];
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << res[i] << " ";
    }
}