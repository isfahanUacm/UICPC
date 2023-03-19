#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, w, h, n, i, j, k, q, x1, y1, x2, y2;
    int room[100][100] = {};
    char names[20][21];
    int occupied[20];
    int overlap;
    int empty;

    cin >> t;
    for (i = 0; i < t; i++)
    {
        cin >> w >> h;
        overlap = 0;
        empty = 0;
        for (j = 0; j < 100; j++)
            for (k = 0; k < 100; k++)
                room[j][k] = 0;

        for (j = 0; j < w; j++)
            for (k = 0; k < h; k++)
                room[j][k] = -1;

        cin >> n;
        for (j = 0; j < n; j++)
        {
            cin >> names[j] >> x1 >> y1 >> x2 >> y2;
            occupied[j] = 0;
            for (k = x1; k < x2; k++)
            {
                for (q = y1; q < y2; q++)
                {
                    if (room[k][q] > 0 && room[k][q] != j + 1)
                    {
                        room[k][q] = -2;
                    }
                    else if (room[k][q] != -2)
                    {
                        room[k][q] = j + 1;
                    }
                }
            }
        }

        for (j = 0; j < w; j++)
        {
            for (k = 0; k < h; k++)
            {
                if (room[j][k] == -2)
                {
                    overlap++;
                }
                else if (room[j][k] > 0)
                {
                    occupied[room[j][k] - 1]++;
                }
                else
                {
                    empty++;
                }
            }
        }

        cout << w * h << endl;
        cout << empty << endl;
        cout << overlap << endl;
        for (j = 0; j < n; j++)
            cout << names[j] << " " << occupied[j] << endl;

        cout << endl;
    }

    return 0;
}