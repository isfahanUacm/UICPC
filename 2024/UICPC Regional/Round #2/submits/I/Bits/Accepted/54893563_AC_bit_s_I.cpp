#include <bits/stdc++.h>
using namespace std;

int f(int a, int b)
{
    int c = a ^ b;
    int otp = 0;
    while(c)
    {
        otp += c & 1;
        c= c >> 1;
    }
    return otp;
}

void solve()
{
    int T; cin >> T;
    for(int COUNTER=0; COUNTER<T; COUNTER++)
    {
       int n; cin >> n;
       vector<int> v;
       for(int c=0; c<n; c++)
       {
            int x; cin >> x;
            v.push_back(x);
       }

       int max = -1;
       for(int i=0; i<n; i++)
       {
           for(int j=i+1; j<n; j++)
           {
               int temp = f(v[i] , v[j]);
               if(temp > max) max = temp;
           }
       }

       cout << max << "\n";
    }
}


int main()
{
    solve();
}
