#include <iostream>

using namespace std;

int main()
{
    int x , y , k ;
    int a[1000][1000] ;
    int maxrol[1000] ;
    cin >> y >> x >> k ;
    for (int j = 0 ; j < y ; j++)
    {
        for (int i = 0 ; i < x ; i++)
        {
            cin >> a[j][i] ;
        }
    }
    for (int j = 0 ; j < y ; j++)
    {
        int max = a[j][0] ;
        for (int i = 0 ; i < x ; i++)
        {
            if (a[j][i] > max)
                max = a[j][i] ;
        }
        maxrol[j] = max ;
    }
    for (int i = 0 ; i < k ; i++)
    {
        int min = 101 ;
        int imin = 0 ;
        for (int j = 0 ; j < y ; j++)
        {
            if( maxrol[j] < 100)
                if (maxrol[j] < min)
                {
                    min = maxrol[j] ;
                    imin = j ;
                }
        }
        maxrol[imin] = 101 ;
    }

    int min = 101 ;
    for (int j = 0 ; j < y ; j++)
    {
        if( maxrol[j] < 100)
            if (maxrol[j] < min)
            {
                min = maxrol[j] ;
            }
    }
    cout << min << endl ;



    return 0;
}
