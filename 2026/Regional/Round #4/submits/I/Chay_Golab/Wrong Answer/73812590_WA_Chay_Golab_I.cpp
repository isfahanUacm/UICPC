#include<iostream>

using namespace std;

int main()
{
    int x;
    cin>>x;
    while (x--)
    {
        int size,max,sum;
        cin>>size>>max>>sum;
        int a = sum/size;
        if(a%2 == 0)
            a--;
        int b = sum - (a* size);
        int max_odd = max;
        if(max_odd %2 ==0)
            max_odd --;
        if(max_odd > a)
            cout<< size -b%2<<endl;
        else
            cout<<size -b<<endl;
    }
    
}