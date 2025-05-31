#include <iostream>
using namespace std;
int main(){
    int count;
    cin>>count;
    int len;
    for (int i = 0; i < count; i++)
    {

        int total=0;
        int temp;
        cin>>len;
        for (int j = 0; j < len; j++)
        {
            cin>>temp;
            total+=temp;
        }
        if (total%2==0)
        {
            cout<<len<<endl;
        }
        else{
            cout<<0<<endl;
        }
        
        
    }
    
    return 0;
}