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
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= j + 1)
            {
                res[j] += arr[i];
            }
        }
    }

    for(int i =0; i<m; i++){
        cout << res[i] << " ";
    }
}