#include <iostream>
using namespace std;
int main(){
    int count;
    cin>>count;
    int a,b;
    for (int i = 0; i < count; i++)
    {
        cin>>a>>b;
        cout<<a-((a - b)/2)<<" "<<(a - b)/2<<endl;
    }
    
    return 0;
}