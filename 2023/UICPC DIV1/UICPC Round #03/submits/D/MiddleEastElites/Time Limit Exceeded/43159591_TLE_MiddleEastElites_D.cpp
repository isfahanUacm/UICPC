#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long int n,counter=0;
    cin>>n;
    long arr[n][2];
    for(int i = 0 ; i< n ; i++)
        for(int j = 0 ; j<2 ;j++ )
        cin>>arr[i][j];
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j >= 0 ; j--){
            counter+=abs(arr[j][0]-arr[i][0])+abs(arr[j][1]-arr[i][1]);
        }
    }
    cout<<counter;
    return 0;
}
