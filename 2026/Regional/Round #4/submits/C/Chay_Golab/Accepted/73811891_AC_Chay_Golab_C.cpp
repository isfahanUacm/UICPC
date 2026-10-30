#include<iostream>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    while(n--)
    {
        long long a;
        cin>>a;
        long long counter = 0;
        long long arr[a][2];
        long long a2 = a-1,down = 0,up = 0;
        for (int i=0;i<a;i++)
        {
            cin>>arr[i][0]>>arr[i][1];
            if(arr[i][0] == arr[i][1]){
                counter += a2;
                --a2;
            }
            else if(arr[i][0] > arr[i][1]){
               ++down;
            }
            else{
                ++up;
            }
        }
        counter += (down * up);

        cout<<counter<<endl;
    }

}