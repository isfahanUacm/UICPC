#include <iostream>
#include <cmath>

using namespace std;
int main (){
int a , b, out1, out2, out3 ;
char c;
cin>>a>>b>>c;
if(c=='L'){
    out2=ceil((double)b/2.0);
    out1=out2;
    out3=a-b;
}
else if(c=='R'){
    out2=ceil(((double)(a-b+1))/2.0);
    out1=b-1;
    out3=out2;
}
cout<<out1<<" "<<out2<<" "<<out3;
//cgfcgfcgf

};