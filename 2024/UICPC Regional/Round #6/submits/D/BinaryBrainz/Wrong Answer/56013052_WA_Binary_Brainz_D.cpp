#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n ;
    cin >> n;

    long int * arr = new long int [n];
    cin >> arr[0];
    long int min = arr[0];
    int minInd = 0;
    long int max = arr[0];
    int maxInd = 0;

    for(int i = 1; i < n; i++) {
        cin >> arr[i];

        if( arr[i] > max) {
            max = arr[i];
            maxInd = i;
        }
        else if (arr[i] < min) {
            min = arr[i];
            minInd = i;
        }
    }

    long int* lower = new long int[n+1];

    if(minInd == 0)
        lower[0] = 0;
    else if (minInd == n-1) {
        lower[n] = 0;
        minInd = n;
    }
    else if(arr[minInd+1] > arr[minInd-1])
        lower[minInd] = 0;
    else
        lower[minInd++ +1] = 0;

    bool a = true;
    for(int i = minInd - 1;i >= 0; i--){
        lower[i] = arr[i] - lower[i+1];
        if(lower[i] < 0) {
            a = false;
            break;
        }
    }
    if(a) {
        for (int i = minInd + 1; i < n+1; i++) {
            lower[i] = arr[i - 1] - lower[i - 1];
            if (lower[i] < 0) {
                a = false;
                break;
            }
        }
    }


    if(maxInd == 0)
        lower[0] = max;
    else if (maxInd == n-1) {
        lower[n] = max;
        maxInd = n;
    }
    else if(arr[maxInd+1] > arr[maxInd-1])
        lower[maxInd] = max;
    else
        lower[maxInd++ +1] = max;

    bool b = true;
    for(int i = maxInd-1;i >= 0; i--){
        lower[i] = arr[i] - lower[i+1];
        if(lower[i] < 0) {
            b = false;
            break;
        }
    }
    if(b) {
        for (int i = maxInd + 1; i < n+1; i++) {
            lower[i] = arr[i - 1] - lower[i - 1];
            if (lower[i] < 0) {
                b = false;
                break;
            }
        }
    }

    if(a && b)
        cout << 2;
    else if ( a || b)
        cout << 1;
    else cout << 0;

    return 0;
}