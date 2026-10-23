#include <iostream>
#include <map>
using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int i=0 ; i<test;i++)
    {
        map<int,int> mp;
        int size,res,max=0,min,javab;
        cin>>size;
        res=size;
        for(int j=0 ; j<size ; j++)
        {
            int k;
            cin>>k;
            if(j==0)
                min=k;
            if(k>max)
                max = k;
            if(k<min)
                min = k;
            if(mp[k] == 0)
                ++mp[k];
            else{
                --res;
            }
        }
        if(res > (max - min))
            cout<<0;
        else
        {
        javab = (max - min)-res +1;
        cout<<javab;
        }
    }

}