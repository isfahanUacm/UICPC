#include <bits/stdc++.h>
using namespace std;

void nextMove(int xi, int yi, int N, int X, int Y, long long &count)
{
    if (xi == N && yi == N)
    {
        count++;
        return;
    }
    for (int i = X; i <= N - xi; i++)
    {
        for (int j = Y; j <= N - yi; j++)
        {
            nextMove(xi + i, yi + j, N, X, Y, count);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X, Y;
    cin >> N >> X >> Y;

    long long count = 0;
    nextMove(0, 0, N, X, Y, count);

    cout << count % (long long)1000000007;
    return 0;
}