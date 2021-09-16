#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    return *max_element(lis, lis + n);
}

int main()
{
    string s;
    int arr[50];
    cin>>s;
    for (int i = 0; i < s.size(); i++){
        arr[i] = s[i];
        //cout<<arr[i]<<" ";
    }
    cout<<26-lis(arr, s.size())<<endl;
    return 0;    
}