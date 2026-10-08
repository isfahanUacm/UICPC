#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0, p = 0, k = 0;
    cin >> n >> p >> k;

    int** penalty = new int* [n + 1];
    for (int i = 0; i < n + 1; i++) {
        penalty[i] = new int[p + 1];
        for (int j = 0; j < p + 1; ++j) {
            penalty[i][j] = 0;
        }
    }

    int** solved = new int* [n + 1];
    for (int i = 0; i < n + 1; i++) {
        solved[i] = new int[3];
        for (int j = 0; j < 3; ++j) {
            solved[i][j] = 0;
        }
        solved[i][2] = i;
    }

    int** logs = new int* [k];
    for (int i = 0; i < k; ++i) {
        logs[i] = new int[4];
        for (int j = 0; j < 4; ++j) {
            logs[i][j] = 0;
        }
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> logs[i][j];
        }
    }

    for (int i = 0; i < k; ++i) {
        int team = logs[i][1];
        int problem = logs[i][2];

        if (penalty[team][problem] == -1)
            continue;

        if (logs[i][3] == 0) {
            penalty[team][problem]++;
        }
        else {
            solved[team][0]++;
            solved[team][1] += logs[i][0] + 20 * penalty[team][problem];
            penalty[team][problem] = -1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            if (solved[j][0] < solved[j + 1][0] ||
                (solved[j][0] == solved[j + 1][0] && solved[j][1] > solved[j + 1][1]) ||
                (solved[j][0] == solved[j + 1][0] && solved[j][1] == solved[j + 1][1] &&
                    solved[j][2] > solved[j + 1][2]))
            {
                swap(solved[j][0], solved[j + 1][0]);
                swap(solved[j][1], solved[j + 1][1]);
                swap(solved[j][2], solved[j + 1][2]);
            }
        }
    }

    for (int i = 1; i < n + 1; ++i) {
        int rank;

        if (i == 1) {
            rank = 1;
        }
        else {
            if (solved[i][0] == solved[i - 1][0] &&
                solved[i][1] == solved[i - 1][1]) {
                rank = i - 1;
            }
            else {
                rank = i;
            }
        }

        cout << rank << ' ' << solved[i][2] << ' '
            << solved[i][0] << ' ' << solved[i][1] << endl;
    }
}