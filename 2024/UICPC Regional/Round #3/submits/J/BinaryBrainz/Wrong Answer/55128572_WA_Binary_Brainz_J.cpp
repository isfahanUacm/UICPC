#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    double ans=0;
   cin>>n;
   double arr[n];
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