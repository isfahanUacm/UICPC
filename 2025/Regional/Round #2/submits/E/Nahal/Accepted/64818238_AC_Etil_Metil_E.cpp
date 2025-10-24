#include<iostream>
#include<cmath>
#include <sstream>
#include<string>
using namespace std;


int main()
{

    long long n,q,k;
    string lang;
    cin>>n>>q>>k>>lang;

    long long opration;
    long long memory;
    memory=n*k;
    opration=((q*2)+(k*5))*n;

    bool memoryLimit=false,TL=false;
    if(memory>(2LL*10000000LL)){
        memoryLimit= true;
    }

    if(lang=="cpp"){
        if(opration>(5LL*100000000LL)){
            TL= true;
        }
    }
    else if(lang=="java"){
        if(opration>(100000000LL)){
            TL= true;
        }
    }
    else{
        if(opration>(2LL*10000000LL)){
            TL=true;
        }
    }

    if(TL && memoryLimit){
        cout<<"TL and ML";
    }
    else if(TL){
        cout<<"TL";
    }
    else if(memoryLimit){
        cout<<"ML";
    }
    else{
        cout<<"OK";
    }

    return 0;
}