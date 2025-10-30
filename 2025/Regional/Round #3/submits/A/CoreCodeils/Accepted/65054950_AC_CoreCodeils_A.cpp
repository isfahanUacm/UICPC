#include <iostream>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    long double e1,e2,v1,v2;
    cin>>v1>>v2>>e1>>e2;
    long double dif1 = e1*n;
    long double dif2 = e2*n;
    long double res1 = v1-dif1;
    long double res2 = v2-dif2;
    if (dif2>v2) {
        res2 =0;
    }
    if (dif1>v1) {
        res1 = 0;
    }
    long double su = res1+res2;
    long double res = (res1/su)*100;

    cout<< fixed << setprecision(7) <<res<<endl;
    return 0;
}