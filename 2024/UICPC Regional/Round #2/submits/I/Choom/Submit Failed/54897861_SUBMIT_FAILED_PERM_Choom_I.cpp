#include <iostream>
using namespace std ;

int main ()
{
    int T , num_inp;
    cin >> T ;
    for(int i=0 ; i<T ; i++)
    {
        cin >> num_inp ; 
        int arr[num_inp] ; 
        for (int i=0 ; i<num_inp ; i++)
        {
            cin >> arr[i];
        }
        int max = 0 ;
        for (int i=0 ; i<num_inp ; i++)
        {
            for(int j=i+1 ; j<num_inp ; j++ )
            {
                int num1 = arr[i] ;
                int num2 = arr[j] ;
                int result = num1 ^ num2 ; 
                
                int counter = 0 ; 
                while(result!=0)
                {
                    result =  result &(result-1) ;
                    counter++ ;
                }
                if (counter > max)
                {
                    max = counter ;
                }
               
                
            }
        }
        cout << max  <<endl ;
    }

    return 0 ;
}