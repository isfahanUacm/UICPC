#include <iostream>
using namespace std ;
int main() {
    int num_inp ;
    int arr[7] ;
    for (int i=0 ; i<7 ; i++)
    {
        arr[i]= 0 ;
    }
    string x ;
    cin >> num_inp ;
    for (int i=0 ; i<num_inp ; i++)
    {
        cin >> x ;
        if (x=="red")
        {
            arr[0]+=1 ;
        }
        if (x=="yellow")
        {
            arr[1]+=1 ;
        }if (x=="green")
        {
            arr[2]+=1 ;
        }if (x=="brown")
        {
            arr[3]+=1 ;
        }if (x=="blue")
        {
            arr[4]+=1 ;
        }if (x=="pink")
        {
            arr[5]+=1 ;
        }if (x=="black")
        {
            arr[6]+=1 ;
        }


    }
     if (arr[0] > 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0 && arr[4] == 0 && arr[5] == 0 && arr[6] == 0) {
         cout << 1;
         return 0;
     }
    int most_value ;
    for (int i=6 ; i>=0 ; i--)
    {
        if (arr[i]!= 0 )
        {
            most_value = i+1 ;
            break ;
        }
    }
    int sum =0 ;
    for (int i=6 ; i>0 ; i--)
    {
        if (arr[i] != 0)
            sum += i + 1 ;
    }
    int result = (arr[0]*( most_value+1) ) + sum ;
    cout << result ;
    return 0;
}
