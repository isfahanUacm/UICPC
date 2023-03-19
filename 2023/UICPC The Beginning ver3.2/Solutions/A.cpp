#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;
    int p = 0;
    string s  = "hello";
    for(auto c: input)
    {
        char target = s[p];
        if(c == target)
            p += 1;
    }
    if(p != 5)
        cout << "NO";
    else
        cout << "YES";
    
}