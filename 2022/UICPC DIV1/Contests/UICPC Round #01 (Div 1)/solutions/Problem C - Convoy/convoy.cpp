#include <bits/stdc++.h>
using namespace std;

#define num long long int
num times[20003], n, k;

bool judge(num tar){
    num c = 0;
    for (int i = 0; i < min(k, n) && tar >= times[i]; ++i) {
         c += 1 + 4 * ((tar/times[i]+1)/2);
         if(c>=n)
             break;
    }
    return c >= n;
}

int main()
{
    cin>>n>>k;
    for (int i = 0; i < n; ++i)
        cin>>times[i];
    sort(times, times+n);
    num lo = 0, hi = 1e12, mid;
    while(lo<hi){
        mid = (lo + hi)/2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid+1;
    }
    cout<<lo<<endl;
    return 0;
}
