#include <bits/stdc++.h>
using namespace std;

bool isKnight(int i, int j, vector<vector<char>> &board)
{
    if (i < 5 && j < 5 && i > 0 && j > 0)
        if (board[i][j] == 'k') return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>> board(5, vector<char>(5));

    int count = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'k')
                count++;
        }

    if (count != 9)
    {
        cout << "invalid";
        return 0;
    }

    int i2, j2;
    bool found = false;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == '.') continue;

            // 2d 1r
            i2 = i + 2;
            j2 = j + 1;
            found = isKnight(i2, j2, board);
            if (found)
            {
                i = 5;
                break;
            }

            // 2d 1l
            i2 = i + 2;
            j2 = j - 1;
            found = isKnight(i2, j2, board);
            if (found)
            {
                i = 5;
                break;
            }

            // 2u 1r
            i2 = i - 2;
            j2 = j + 1;
            found = isKnight(i2, j2, board);
            if (found)
            {
                i = 5;
                break;
            }

            // 2u 1l
            i2 = i - 2;
            j2 = j - 1;
            found = isKnight(i2, j2, board);
            if (found)
            {
                i = 5;
                break;
            }

            //
            // 1d 2r
            i2 = i + 1;
            j2 = j + 2;
            found = isKnight(i2, j2, board);
            if (found)
            {
                i = 5;
                break;
            }

            // 1d 2l
            i2 = i + 1;
            j2 = j - 2;
            found = isKnight(i2, j2, board);
            if (found)
            {
                i = 5;
                break;
            }

            // 1u 2r
            i2 = i - 1;
            j2 = j + 2;
            found = isKnight(i2, j2, board);
            if (found)
            {
                i = 5;
                break;
            }

            // 1u 2l
            i2 = i - 1;
            j2 = j - 2;
            found = isKnight(i2, j2, board);
            if (found)
            {
                i = 5;
                break;
            }
        }

    if (found)
        cout << "invalid";
    else
        cout << "valid";

    return 0;
}