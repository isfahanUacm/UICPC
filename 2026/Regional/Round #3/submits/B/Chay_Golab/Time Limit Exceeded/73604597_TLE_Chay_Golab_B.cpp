#include <iostream>
using namespace std;


int main()
{
    int n;
    cin>>n;
    for(int i = 0 ;i<n ;i++)
    {
        int size = 0;
        int x;
        cin>>x;
        // int arr[x];
        //  for(int j = 1 ; j<=x ; j++)
        //  {
        //     arr[j-1] = j;
        //  }
         for(int j=1; j<x; j++)
         {
            for(int k=j+1; k<=x; k++)
            {
                if(((j * k) % (k - j) )== 0)
                    size++;
            }
         }
         cout<<size<<endl;
    }
}