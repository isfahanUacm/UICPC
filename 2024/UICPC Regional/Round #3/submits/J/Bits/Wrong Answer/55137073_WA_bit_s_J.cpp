#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const maxI = 1e5*2;

void solve(){
    vector<double> v(20);
        v[0] = 2.00;
        v[1] = 1.00;
        v[2] = 0.5;
        v[4] = 0.25;
        v[8] = 0.125;
        v[16] = 0.0625;

        int n; cin >> n;
        double sum = 0.00;
        for(int i=0; i<n; i++)
        {
            int x; cin >> x;
            if(x==0){
                sum += v[x];
                continue;
            }
            int num = 1;
            while (x) {
                sum += (x&1)*v[num];
                x = x >> 1;
                num*=2;
            }
        }

        cout << sum;
 return;
}

int main()
{
    solve();
    return 0;
}
