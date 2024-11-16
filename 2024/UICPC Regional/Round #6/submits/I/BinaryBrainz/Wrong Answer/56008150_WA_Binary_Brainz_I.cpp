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
    int i = 0;
    while(i < n) {
        while (h[i] + up < v[i])
            up++;

        int j = i;
        while (h[j]+up == v[j]) {
            j++;
            if(j == n) {
                j--;
                break;
            }
        }

        if ((h[j] + up > v[j]) || (j == n-1))
            break;
        else {
            up++;
            break;
        }
    }

    cout << up;

    return 0;
}