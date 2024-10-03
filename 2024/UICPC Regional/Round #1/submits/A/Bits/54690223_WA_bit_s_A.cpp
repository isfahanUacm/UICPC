#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s1 = "", s2 = "";

bool flag = true;
void f(string s, int i){
    if(s.size() > 5) {cout << "error " << i << "\n";flag = false;}

    if(s[1] == '-')
    {
        s1 = s[0];
        s2 += s[2];
        if(s.size() > 3)
        {
            s2 += s[3];
        }
    }
    else if(s[2] == '-')
    {
        s1 = s1 + s[0] + s[1];
        s2 = s2 + s[3];
        if(s.size() > 4)
            s2 = s2+s[4];
    }
    else {cout << "error " << i << "\n"; flag = false;}

}

int main()
{
    int n; cin >> n;
    int a=0, b=0;
    string s;
    cin >> s;
    f(s,1);
    a = stoi(s1);
    b = stoi(s2);

    for(int i=2; i<=n; i++)
    {
        if(!flag)
            break;
        cin >> s;
        s1 = ""; s2 = "";
        f(s,i);
        int x = stoi(s1), y = stoi(s2);


        int num = (x+y) % 4;
        if(num == 0 || num == 3)
        {
            if((a == 11 || b==11) && !(a==x && b==y))
            {
                cout << "error " << i << "\n";
                flag = false;
            }
            else if((x==a+1 && y==b) || (y==b+1 && x==a) || (y==b && x==a))
            {
                a = x; b = y;
            }
            else
            {
                cout << "error " << i << "\n";
                flag = false;
            }

        }
        else
        {
            if((a == 11 || b==11) && !(a==y && b==x))
            {
                cout << "error " << i << "\n";
                flag = false;
            }
            else if((y==a+1 && x==b) || (x==b+1 && y==a) || (x==b && y==a))
            {
                a = y; b = x;
            }
            else
            {
                cout << "error " << i << "\n";
                flag = false;
            }
        }
    }
    if(flag)
        cout << "ok\n";

}
