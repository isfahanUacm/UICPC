#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

void remove(string  &, int  , int );

void func1(string &, string);
bool func2(string   , string &);
bool func3(string   , string &);
int main()
{
    int t;
    cin >> t;
    string u[101];
    string v[101];

    for(int i = 0 ; i < t; i++)
        cin >> u[i] >> v[i];

    for(int i = 0 ; i < t; i++)
    {
        if((u[i] == "A" || u[i] == "B" || u[i] == "C") && (v[i] == "A" || v[i] == "B" || v[i] == "C"))
            cout << "NO" << endl;
        else if((u[i] == "AA" || u[i] == "BB" || u[i] == "CC" || u[i] == "ABAB" || u[i] == "BCBC") && (v[i] == "AA" || v[i] == "BB" || v[i] == "CC" || v[i] == "ABAB" || v[i] == "BCBC"))
            cout << "YES" << endl;

        else
        {
            func1(u[i] , v[i]);

            if(func2(v[i] , u[i]))
                cout << "YES" << endl;
            else if(func3(v[i] , u[i]))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

    }

}

void func1(string & u , string v)
{
    for(int i = 0 ; i < u.length() ; i++)
    {
        if(u[i] == 'A' && u[i + 1] == 'B' && u[i + 2] == 'A' && u[i + 3] == 'B')
        {
            remove(u , 4 , i);
            func1(u , v);
        }
        else if((u[i] == 'B' && u[i + 1] == 'C' && u[i + 2] == 'B' && u[i + 3] == 'C'))
        {
            remove(u , 4 , i);
            func1(u , v);
        }
        else if(u[i] == u[i+1])
        {
            remove(u , 2 , i);
            func1(u , v);
        }
    }

}

bool func2(string v , string &u)
{
    for(int i = 0 ; i < v.length() ; i++)
    {
        if(v[i] == 'A' && v[i + 1] == 'B' && v[i + 2] == 'A' && v[i + 3] == 'B')
        {
            remove(v , 4 , i);
            func2(v , u);
        }
        else if((v[i] == 'B' && v[i + 1] == 'C' && v[i + 2] == 'B' && v[i + 3] == 'C'))
        {
            remove(v , 4 , i);
            func2(v , u);
        }
        else if(v[i] == v[i+1])
        {
            remove(u , 2 , i);
            func2(v , u);
        }
    }

    if(v==u)
        return 1;
    return 0;

}

bool func3(string v , string &u)
{
    for(int i = 0 ; i < v.length() ; i++)
    {
        if(v[i] == v[i+1])
        {
            remove(u , 2 , i);
            func2(v , u);
        }

        else if(v[i] == 'A' && v[i + 1] == 'B' && v[i + 2] == 'A' && v[i + 3] == 'B')
        {
            remove(v , 4 , i);
            func2(v , u);
        }
        else if((v[i] == 'B' && v[i + 1] == 'C' && v[i + 2] == 'B' && v[i + 3] == 'C'))
        {
            remove(v , 4 , i);
            func2(v , u);
        }

    }

    if(v==u)
        return 1;
    return 0;

}



void remove(string &u , int Rlen , int index)
{
    string tmp;
    int j = 0;
    //cout << strlen(u);
    if(Rlen == 4)
    {
        for(int i = 0; i < u.length(); i++)
        {
            if(i != index && i != index + 1 && i != index + 2 && i != index + 3)
            {
                tmp += u[i];

                j++;
            }
        }
    }




    else

    {
        for(int i = 0; i < u.length(); i++)
        {
            if(i != index && i != index + 1)
            {
                tmp += u[i];
                j++;
            }
        }
    }

    u = tmp;

}

