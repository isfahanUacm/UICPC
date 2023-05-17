#include <iostream>
using namespace std;

int main()
{
    int r;
    int c;
    cin >> r >> c;
    int* arr_r = new int[r];
    int* arr_c = new int[c];

    int max_r = 0;
    for (int i = 0; i < r; i++)
    {
        cin >> arr_r[i];
        if (arr_r[i] > max_r)
        {
            max_r = arr_r[i];
        }
    }
    int max_c = 0;
    for (int i = 0; i < c; i++)
    {
        cin >> arr_c[i];
        if (arr_c[i] > max_c)
        {
            max_c = arr_c[i];
        }
    }

    if (max_r == max_c)
        cout << "possible";
    else
        cout << "impossible";


}