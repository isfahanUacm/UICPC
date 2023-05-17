#include <iostream>

using namespace std;

int main()
{
    int x , y ;
    int a[1000] , b[1000] ;
    cin >> x >> y ;
    for ( int i = 0 ; i< y ; i++ )
    {
        cin >> a[i] ;
    }
    for ( int i = 0 ; i< x ; i++ )
    {
        cin >> b[i] ;
    }
    if ( a[y-1] == b[0])
        cout << "possible" << endl ;
    else
        cout << " impossible" << endl ;
    return 0;
}
