#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    string str1 , str2;
    int result = 0 , tmpI , tmpJ;
    cin >> str1 >> str2;
    tmpI = 0;
    tmpJ = str1.length() - 1;

    for(int i = 1 ; true ; i ++)
    {
        if(str1[tmpI] == str2[tmpI])
            tmpI++;
        if(str1[tmpJ] == str2[tmpJ])
            tmpJ--;
        if(str1[tmpI] != str2[tmpI] && str1[tmpJ] != str2[tmpJ])
            break;
    }

    reverse(str1.begin() + tmpI , str1.begin() + tmpJ + 1);


    if(str1 == str2)
    {
        result++;
        tmpI--;
        tmpJ++;
        while(str1[tmpI] == str1[tmpJ])
        {
            if(tmpI < 0 || tmpJ >= str1.length())
                break;
            result++;
            tmpJ++;
            tmpI--;
        }
    }


    cout << result;
}
