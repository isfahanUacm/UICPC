#include <bits/stdc++.h>
using namespace std;
long long int MAX_n = (360*60*60);
double Pi = acos(-1);
long long int m, n, tet, minn, sec;
double r;
bool cut[(360*60*60)+1];

int main()
{
    cin>>m;
    while(m--){
        fill_n(cut, MAX_n, false);
        cin>>r>>n>>tet>>minn>>sec;
        n = min(n, MAX_n);
        long long int cutstep = 3600*tet+60*minn+sec;
        for (int i = 0; i < n; ++i)
            cut[i*cutstep%MAX_n] = true;
        cut[MAX_n]=true;
        int pre=0, deg = 0;
        for (int i = 1; i <= MAX_n; ++i)
            if(cut[i])
                deg = max(deg, i-pre),pre = i;
        printf("%lf\n", (Pi * r * r * (1.0*deg/MAX_n)));
    }
    return 0;
}