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
    int count = 0;

    for(int i = 1; i < n; i++) {
        cin >> arr[i];

        if (arr[i] < min) {
            min = arr[i];
            minInd = i;
        }
    }

    long int* lower = new long int[n+1];

    for( int j = 0 ; j <= min;j++){
        lower[minInd] = j;

        bool a = true;

        for (int i = minInd + 1; i < n+1; i++) {
            lower[i] = arr[i - 1] - lower[i - 1];
            if (lower[i] < 0) {
                a = false;
                break;
            }
        }
        if(a) {
            for(int i = minInd - 1;i >= 0; i--){
                lower[i] = arr[i] - lower[i+1];
                if(lower[i] < 0) {
                    a = false;
                    break;
                }
            }
        }

        if(a)
            count++;
    }

    cout << count;

    return 0;
}