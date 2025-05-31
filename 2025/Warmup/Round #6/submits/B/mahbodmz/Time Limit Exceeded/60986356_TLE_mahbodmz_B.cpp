#include <iostream>
#include <numeric>
using namespace std;
int main(){
    int count;
    cin>>count;
    for (int p = 0; p<count; p++){
        long number;
        cin >>number;
        int a;
        int b;
        long min = 2000000000;
        for(int i = 1; i < (number/2) + 1; i ++){
            if(lcm(i, number - i) < min){
                a = i;
                b = number - i;
                min = lcm(a,b);
            }
        }
        
        cout<<a<<" "<<b<<endl;
    }

    return 0;
}