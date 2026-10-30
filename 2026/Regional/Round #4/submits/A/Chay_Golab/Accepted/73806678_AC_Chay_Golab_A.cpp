#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int j;
        cin>>j;
        int arr[j];
        bool Isok = true;

        for(int i=0; i<j;i++)
        {
            cin>>arr[i];

            if(arr[i]>(i+1))
            {
                Isok = false;
            }
        }

        if(Isok == false)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<"\n";
   }
}