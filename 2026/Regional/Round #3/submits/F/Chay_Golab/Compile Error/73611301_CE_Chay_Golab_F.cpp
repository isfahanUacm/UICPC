#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int x,ok;
    cin>>x;
    while(x--){
        ok=0;
        string s;
        cin>>s;
        for (int i = 1; i < s.size; i++)
        {
            if(s[0] != s[i])
                ok = 1;
        }
        if(ok == 1)
            cout<<0<<endl;
        else{
            cout<<(2*s.size - 2)<<endl;
        }
        
    }

    return 0;
}