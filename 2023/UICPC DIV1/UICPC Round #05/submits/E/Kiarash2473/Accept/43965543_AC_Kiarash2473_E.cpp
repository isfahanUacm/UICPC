#include <iostream>
#include <math.h>
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

    int res[3];
    int digit_3;
    for (int i = 0; i < n; i++)
    {
        digit_3 = arr[i] / 1000;
        digit_3--;

        for (int k = 0; k < 3; k++)
        {
            res[k] = digit_3;
            int temp = digit_3;
            int tmp[3];
            for (int j = 0; j < 3; j++)
            {
                tmp[j] = temp % 10;
                temp /= 10;
            }
            for (int j = 0; j < 3; j++)
            {
                res[k] *= 10;
                res[k] += tmp[j];
            }
            digit_3++;
        }

        int dif_0 = abs(arr[i] - res[0]);
        int dif_1 = abs(arr[i] - res[1]);
        int dif_2 = abs(arr[i] - res[2]);

        if (dif_0 <= dif_1 && dif_0 <= dif_2)
            cout << res[0] << endl;
        if (dif_1 <= dif_2 && dif_1 < dif_0)
            cout << res[1] << endl;
        if (dif_2 < dif_1 && dif_2 < dif_0)
            cout << res[2] << endl;
    }
}