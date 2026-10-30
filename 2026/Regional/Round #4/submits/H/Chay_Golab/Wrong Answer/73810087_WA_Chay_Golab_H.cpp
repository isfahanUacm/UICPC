#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int a;
        cin>>a;
        bool All_One = true;
        int arr[a];
        for(int i=0; i<a ; i++)
        {
            cin>>arr[i];
            if(arr[i] != 1)
                All_One = false;
        }
        if(All_One == true)
            {
                cout<<0<<endl;
                continue;
            }
        int top=0,end=a;
        
        for(int i=0;i<a ; i++)
        {
            if(arr[i] != 1)
                top = i;

        }
        for(int i=a;i>0;i--)
        {
            if ((arr[i])!=1)
            {
                end = i;
            }
        }
        bool mokhtalef=true;
        for(int i = top; i<=end ; i++)
        {
            if(arr[top] != arr[i])
            { mokhtalef = false;
            }
        }
        if(mokhtalef == false)
            cout<<1<<endl;
        else
            cout<<2<<endl;
    
    }
}