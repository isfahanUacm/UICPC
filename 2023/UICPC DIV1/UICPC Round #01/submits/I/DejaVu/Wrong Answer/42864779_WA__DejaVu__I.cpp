#include <iostream>

using namespace std;

int main()
{
    int n ;
    int a[1000000] ;
    int f[1000000] ;
    cin >> n ;
    for (int i = 0 ; i < n ; i++)
        cin >> a[i] ;
    for (int i = 1 ; i < n-1 ; i++)
    {
        int sum1 = 0 ;
        int sum2 = 0 ;
        for (int k = 0 ; k < i ; k++)
            sum1 += a[i]*a[i] ;
        for (int k = i ; k < n ; k++)
            sum2 += a[i] ;
        f[i-1] = sum1*sum2 ;
    }
    int max = f[0] ;
    for (int i = 0 ; i < n-2 ; i++)
    {
        if (f[i] > max )
            max = f[i] ;
    }
    cout << max << endl ;
    return 0;
}
