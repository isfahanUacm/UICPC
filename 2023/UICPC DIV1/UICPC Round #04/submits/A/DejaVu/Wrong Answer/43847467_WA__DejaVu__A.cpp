#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr, arr + n);
    int temp;
     for (int i = 0, j = n - 1; i < n/2; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==arr[i+1]){
            continue;
        }
        else{
            break;
        }
    }
    cout<<max(n+arr[n-1]+1,arr[0]+2+i);

    return 0;
}
