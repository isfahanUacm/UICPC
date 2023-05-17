#include <iostream>

using namespace std;

int main()
{
    int n ;
    cin >> n ;
    int k1 , k2 ;
    bool b = false ;
    for ( int i = 1 ; i <= 1000000000 ; i++ )
    {
        for ( int j = 1 ; j<= i ; j++ )
        {
            if ( i*i - j*j == n )
            {
                b = true ;
                k1 = i ;
                k2 = j ;
                break ;
            }
        }
        if (b)
            break;
    }
    if ( b)
        cout << k1 << " " << k2 << endl ;
    else
        cout << "impossible" << endl ;
    return 0;
}
