#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#include<cmath>
int main() {
int n, max,m=0;
long long t,sum=0;

cin>>n>>t;
int arr[n];

for(int i=0;i<n;i++){
    cin>>arr[i];
}
max= arr[0];
for(int j=1;j<n;j++){
    if(arr[j]>max){
        max=arr[j];
    }
}
if(t==n){
    cout<<max;
}
else{
    for(int k=0;k<n;k++){
        if(arr[k]<t){
            m++;
        }
        else{
            sum+=arr[k];
        }
    }
    long long s= ceil(sum/(t-m));
   for(long long j=s;j<=pow(10,12);j++){

       long long sum2=0;
       for(int k=0;k<n;k++){
           sum2+= ceil((double)arr[k]/(double)j);
       }
       if(sum2<=t){
           cout<<j;
           return 0;
       }
   }
}

    return 0;
}