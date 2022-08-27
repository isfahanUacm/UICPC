#include <iostream>

using namespace std ;

int Sum = 0 ;
int number = 0 ;

void check(char * arr);
void Repeatition(char *arr)
{
    bool check1 = false  ;
    for ( int i =  0 ; i < number ; i ++ )
    {
         if (arr[i] == '0')
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


void conversion (char * arr , int index)
{
    Sum += 1 ;
    arr[index] = 'Z' ;
    for ( int i =  0 ; i < number ; i ++ )
    {

        if (i > index )
        {
            arr[i] =  '0' ;
        }
    }
    Repeatition(arr) ;
}


void check (char * arr)
{
   int index = 0 ;
   for ( int i =  0 ; i < number ; i ++ )
   {

       if (arr[i] == '0')
       {
           index =  i ;
       }
   }
   conversion (arr, index) ;

}


int main()
{

    cin >> number ;
    int sum = 0 ;
    char array[100] ;
    for ( int i =  0 ; i < number ; i ++ )
    {
        cin >> array[i] ;
        if (array[i] == '0')
        {
            sum+= 1 ;
        }
    }

    if (sum != 0 )
    {
        check(array) ;
    }
    else
    {
        cout << 0 << endl;
    }




    return 0 ;
}
