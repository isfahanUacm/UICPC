#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 2 + arr[i] > max)
            max = arr[i] + 2 + i;
    }
    cout << max;
}