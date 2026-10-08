#include <iostream>
using namespace std;

int main()
{
    int n, s , a, b , c;
    char d;
    cin >> n >> s >> d;
    if (d=='L')
    {
        c = n - s;
        if (s % 2 == 1) {
            a = s / 2 + 1;
            b = s / 2 + 1;
        }
        else {
            a = s / 2;
            b = s / 2;
        }
    }
    else if(d=='R')
    {
        a = s - 1;
        if (n-s % 2 == 1) {
            b = (n-s+1) / 2;
            c = (n - s + 1) / 2;
        }
        else {
            c = (n - s ) / 2 +1;
            b = (n - s) / 2 +1;
        }
    }

    cout << a << " " << b <<" "<< c;
}

