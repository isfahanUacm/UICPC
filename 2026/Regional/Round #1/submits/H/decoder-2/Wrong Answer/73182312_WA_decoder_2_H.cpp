#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#include<cmath>
int main() {
int n;
long long t;

cin>>n>>t;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
for(long long j=t;j>=1;j--){
    long long sum=0;
    for(int k=0;k<n;k++){
        sum += ceil(((double)arr[k]/ (double)j));
    }
    if(sum > t && j!=t){
        cout << j+1;
        return 0;
    }
    else if( sum >t && j==t){
       cout<<j;
       return 0;
    }
}

    return 0;
}