#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin >> n;

    int * h = new int[n];
    int* v = new int[n];

    for(int i = 0; i < n ; i++){
        cin >> h [i];
    }
    for(int i = 0; i < n ; i++){
        cin >> v[i];
    }

    int up = 0;

        up = v[0] - h[0];
        if (up < 0)
            up = 0;

        int j = 0;
        while (h[j]+up == v[j]) {
            j++;
            if(j == n) {
                j--;
                break;
            }
        }

        if (h[j] + up == v[j] && (j != n-1))
            up++;
        else if (h[j] + up < v[j])
            up++;

    cout << up;

    return 0;
}