#include <iostream>

using namespace std;

int main()
{
    int x , y ;
    int a[100] , b[100] ;
    cin >> y >> x ;
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
