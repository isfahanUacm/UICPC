#include <iostream>

using namespace std ;

int Sum = 0 ;
int16_t number = 0 ;

void check(char * arr);
void Repeatition(char *arr)
{
    bool check1 = false  ;
    for ( int16_t i =  0 ; i < number ; i ++ )
    {
         if (arr[i] == 'O')
         {
             check1 = true ;
             break ;
         }
    }
    if ( check1 )
    {
        check(arr);
    }
    else
    {
        cout << Sum << endl;
    }
}


void conversion (char * arr , int16_t index)
{
    Sum += 1 ;
    arr[index] = 'Z' ;
    for ( int16_t i =  0 ; i < number ; i ++ )
    {

        if (i > index )
        {
            arr[i] =  'O' ;
        }
    }
    Repeatition(arr) ;
}


void check (char * arr)
{
   int16_t index = 0 ;
   for ( int16_t i =  0 ; i < number ; i ++ )
   {
       if (arr[i] == 'O')
       {

           index = i ;
       }

   }
   conversion (arr, index) ;

}


int main()
{

    cin >> number ;
    int16_t sum = 0 ;
    char array[61] ;
    int index = 0 ;
    for ( int16_t i =  0 ; i < number ; i ++ )
    {
        cin >> array[i] ;
        if (array[i] == 'O')
        {
            sum+= 1 ;
            index = i ;
        }

    }

    if (sum != 0 )
    {
        conversion(array , index) ;
    }
    else
    {
        cout << 0 << endl;
    }




    return 0 ;
}
