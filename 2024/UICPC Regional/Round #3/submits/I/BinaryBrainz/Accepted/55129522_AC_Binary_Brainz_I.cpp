#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int h;
    cin>>n;
    int* arr= new int [n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }

    cin >> h;
    int min = h;
    int minset;

    for(int i = 0 ; i < n;i++){
        int res = h % arr[i];

        if(res < min) {
            min = res;
            minset = arr[i];
        }
    }

    cout << minset;
   return 0;
}