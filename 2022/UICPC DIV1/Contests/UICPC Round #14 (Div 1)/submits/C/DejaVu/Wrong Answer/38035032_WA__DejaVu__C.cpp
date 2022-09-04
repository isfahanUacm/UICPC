#include <iostream>
using namespace std;
int main(void)
{
    char Array[5][5];
    int tmp= 0;
    for(int i = 0 ; i < 5 ; i++)
        for(int j = 0 ; j < 5 ; j++)
        {
            cin >> Array[i][j];
            if(Array[i][j] == 'k')
                tmp++;
        }
    bool check = 1;
    if(tmp != 9)
        cout << "invalid";
    else
    {
        for(int i = 0 ; i < 5 ; i++)
            for(int j = 0 ; j < 5 ; j++)
            {
                char tmp2 = Array[i][j];
                if(tmp2 == 'k')
                {
                    if(i + 2 >=0 && i + 2 < 5 && j + 1 >= 0 && j + 1 < 5 && Array[i + 2][j+1] == 'k')
                    {
                        cout << "invalid";
                        check = 0;
                        break;
                    }
                    else if( i + 2 >=0 && i + 2 < 5 && j - 1 >= 0 && j - 1 < 5 && Array[i + 2][j-1] == 'k')
                    {
                        cout << "invalid";
                        check = 0;
                        break;
                    }
                    else if( i - 2 >=0 && i - 2 < 5 && j + 1 >= 0 && j + 1 < 5 && Array[i - 2][j+1] == 'k')
                    {
                        cout << "invalid";
                        check = 0;
                        break;
                    }
                    else if ( i - 2 >=0 && i - 2 < 5 && j - 1 >= 0 && j - 1 < 5 && Array[i - 2][j-1] == 'k')
                    {
                        cout << "invalid";
                        check = 0;
                        break;
                    }
                    else if( i + 1 >=0 && i + 1 < 5 && j + 2 >= 0 && j + 2 < 5 && Array[i + 1][j+2] == 'k')
                    {
                        cout << "invalid";
                        check = 0;
                        break;
                    }
                    else if( i + 1 >=0 && i + 1 < 5 && j - 2 >= 0 && j - 2 < 5 && Array[i + 1][j-2] == 'k')
                    {
                        cout << "invalid";
                        check = 0;
                        break;
                    }
                    else if(i -1 >=0 && i -1 < 5 && j + 2 >= 0 && j+2 < 5 && Array[i - 1][j+2] == 'k' )
                    {
                        cout << "invalid";
                        check = 0;
                        break;
                    }
                    else if( i -1 >=0 && i-1 < 5 && j -2 >= 0 && j -2 < 5 && Array[i - 1][j-2] == 'k' )
                    {
                        cout << "invalid";
                        check = 0;
                        break;
                    }
                }
            }

        if(check)
            cout << "valid";
    }


}
