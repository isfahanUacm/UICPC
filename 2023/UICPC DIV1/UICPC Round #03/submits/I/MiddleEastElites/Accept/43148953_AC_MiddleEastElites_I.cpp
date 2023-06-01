#include <iostream>

using namespace std;

int main()
{
    long long int s ;
    cin>>s;
    if(s%2==1)
    cout<<"still running";
    else
    {
        long long int arr[s];
        for(int i =0 ; i <s ; i++)
            cin>>arr[i];
        long long int count = 0;
        for(int i = 1 ; i<s ; i+=2){
            count+=arr[i]-arr[i-1];
        }
        cout<<count;
    }

    return 0;
}
