#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int main(){
    int count;
    int l,r;
    cin>>count;
    for (int i = 0; i < count; i++)
    {
        cin>>l;
        cin>>r;
        int min=sqrt(l);
        if (min*min==l)
        {
            min--;
        
        }
        int max=sqrt(r);
        cout<<max-min<<endl;
        
    }
    
    return 0;
}