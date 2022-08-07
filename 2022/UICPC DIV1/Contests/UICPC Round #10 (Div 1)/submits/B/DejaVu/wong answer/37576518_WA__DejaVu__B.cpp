#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

char * shift_left(char [200] , int );
void func(char [] , char []);

int main()
{
    int t;
    cin >> t;
    char u[100][200];
    char v[100][200];

    for(int i = 0 ; i < t; i++)
        cin >> u[i] >> v[i];

    for(int i = 0 ; i < t; i++)
    {
        if(!strcmp(u[i] , "A") || !strcmp(u[i] , "B") || !strcmp(u[i] , "C") || !strcmp(v[i] , "A") || !strcmp(v[i] , "B") || !strcmp(v[i] , "C"))
            cout << "NO" << endl;
        else if(!strcmp(u[i] , "AA") || !strcmp(u[i] , "BB") || !strcmp(u[i] , "CC") || !strcmp(u[i] , "ABAB") || !strcmp(u[i] , "BCBC") && (!strcmp(v[i] , "AA") || !strcmp(v[i] , "BB") || !strcmp(v[i] , "CC") || !strcmp(v[i] , "ABAB") || !strcmp(v[i] , "BCBC")))
            cout << "YES" << endl;
        else
        {
            func(u[i] , v[i]);
        }

    }


    cout << endl;
}

char * shift_left(char u[] , int indx)
{
    int j = 0;
    char  tmp[strlen(u) - 2];
    for(int i = 0 ; i < strlen(u) ; i++)
    {
         if(i != indx && i != indx + 1)
         {
             tmp[j] = u[i];
             j++;
         }
    }


    return tmp;
}

void func(char u[] , char v[])
{
    for(int i = 0 ; i < strlen(u) ; i++)
    {
        if(u[i] == u[i + 1])
        {

            int j = 0;
            char tmp[strlen(u) - 2];
            for(int k = 0 ; k < strlen(u) ; k++)
            {
                 if(k != i && k != i + 1)
                 {
                     tmp[j] = u[k];
                     j++;
                 }
            }

            bool check = true;
            for(int k = 0; k < strlen(v); k++)
            {
                if(tmp[k] != v[k])
                {
                    check = 0;
                    break;
                }
            }
            if(check)
                cout << "YES" << endl;

//-----------------------------------------------------------------------------

            else
            {
                char  tmp[strlen(u)];
                for(int k = 0 ; k < strlen(u) ; k++)
                {
                    if(k == i)
                    {
                        tmp[k] = 'B';
                        tmp[k+1] = 'B';
                    }
                    if(k != i && k != i + 1)
                    {
                        tmp[k] = u[k];
                    }
                }

                bool check = true;
                for(int k = 0; k < strlen(v); k++)
                {
                    if(tmp[k] != v[k])
                    {
                        check = 0;
                        break;
                    }
                }
                if(check)
                    cout << "YES" << endl;

//----------------------------------------------------------------------------------------

                else
                {
                    char  tmp[strlen(u)];
                    for(int k = 0 ; k < strlen(u) ; k++)
                    {
                        if(k == i)
                        {
                            tmp[k] = 'C';
                            tmp[k+1] = 'C';
                        }
                        if(k != i && k != i + 1)
                        {
                            tmp[k] = u[k];
                        }
                    }

                    bool check = true;
                    for(int k = 0; k < strlen(v); k++)
                    {
                        if(tmp[k] != v[k])
                        {
                            check = 0;
                            break;
                        }
                    }
                    if(check)
                        cout << "YES" << endl;

                    else
                    {
                        char  tmp[strlen(u)];
                        for(int k = 0 ; k < strlen(u) ; k++)
                        {
                            if(k == i)
                            {
                                tmp[k] = 'A';
                                tmp[k+1] = 'A';
                            }
                            if(k != i && k != i + 1)
                            {
                                tmp[k] = u[k];
                            }
                        }

                        bool check = true;
                        for(int k = 0; k < strlen(v); k++)
                        {
                            if(tmp[k] != v[k])
                            {
                                check = 0;
                                break;
                            }
                        }
                        if(check)
                            cout << "YES" << endl;



                    }
                }
            }


        }


    }
}
