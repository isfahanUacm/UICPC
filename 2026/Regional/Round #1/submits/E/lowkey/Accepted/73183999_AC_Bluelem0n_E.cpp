#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;

    int** ans = new int* [p];

    for (int i = 0; i < p; i++)
    {
        ans[i] = new int[3];

        for (int j = 0; j < 3; j++)
        {
            ans[i][j] = 0;
        }
    }

    string** arr = new string* [n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new string[2 * p];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * p; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j][2 * i] == "+")
            {
                ans[i][0]++;

                ans[i][1]++;
            }
            else if (arr[j][2 * i] == "-")
            {
                if (stoi(arr[j][2 * i + 1]) > 0)
                {
                    ans[i][1]++;
                }
            }

            ans[i][2] += stoi(arr[j][2 * i + 1]);
        }
    }

    for (int i = 0; i < p; i++)
    {
        cout << ans[i][0] << " "
            << ans[i][1] << " "
            << ans[i][2] << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    for (int i = 0; i < p; i++)
    {
        delete[] ans[i];
    }

    delete[] ans;

    return 0;
}