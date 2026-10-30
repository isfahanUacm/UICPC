#include<iostream>

using namespace std;

int main()
{
    long long x;
    cin>>x;
    while (x--)
    {
        long long size,max,sum;
        cin>>size>>max>>sum;
        if(sum<= size){
            cout<<sum<<endl;
            continue;
        }
        long long a = sum/size;
        if(a%2 == 0)
            a--;
        long long b = sum - (a* size);
        long long max_odd = max;
        if(max_odd %2 ==0)
            max_odd --;
        if(max_odd > a)
            cout<< size -b%2<<endl;
        else
            cout<<size -b<<endl;
        
    }
    
}