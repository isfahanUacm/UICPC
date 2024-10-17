#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long double ans=0;
   cin>>n;
   long double * arr=new long double[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    for (int i = 0; i < n; ++i) {
        if(arr[i]==0)
            ans+=2;
        else
        {
            ans+=1/arr[i];
        }
    }
    cout<<ans;
}