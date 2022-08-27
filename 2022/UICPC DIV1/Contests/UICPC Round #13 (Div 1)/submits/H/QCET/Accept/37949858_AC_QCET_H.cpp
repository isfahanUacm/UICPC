#include <iostream>
using namespace std ;
int main()
{

    int times = 0 ;
    char Letter ;
    cin >> times ;
    long long  number = 1 ;
    for ( int i = 0 ; i < times-1 ; i ++)
    {
        number*=2 ;
    }
    long long sum = 0 ;
    while (times--)
    {
        cin >>Letter ;
        if ( Letter == 'O')
        {
            sum+=number ;
        }
        number /= 2 ;
    }
    cout << sum << endl;

return 0 ;
}