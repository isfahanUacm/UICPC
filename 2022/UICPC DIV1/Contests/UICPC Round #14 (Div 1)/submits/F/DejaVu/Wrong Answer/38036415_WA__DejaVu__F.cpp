#include <algorithm>
#include<iostream>
#include<string>
using namespace std;

bool replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

bool find_revers(string , string , string , int &);

void pre_and_then(string  , string  , string  , int &);

int main(void)
{
    string str1;
    string str2 ;
    string tmp;
    bool check = 1;
    int result = 0;
    cin >> str1 >> str2;


    for(int i = 0 ; i < str1.length() ; i++)
    {
        if(!check && str1[i] == str2[i])
            break;
        if(str1[i] != str2[i])
        {
            tmp+= str1[i];
            check = 0;
        }
    }

    if(find_revers(str1 , str2 , tmp , result))
    {
        pre_and_then(str1 , str2 , tmp , result);
    }


}

bool find_revers(string str1 , string str2 , string tmp , int &result)
{
    string tmp2 = tmp;
    string tmpStr1 = str1;
    reverse(tmp.begin(), tmp.end());
    replace(tmpStr1 , tmp2 , tmp);

    if(tmpStr1 == str2)
    {
        result++;
        return 1;
    }

    return 0;
}
void pre_and_then(string str1 , string str2 , string tmp , int &result)
{
    int MainIndx = str1.find(tmp);
    for(int i = 1 ;; i++)
    {
        if(MainIndx - i < 0)
            break;
        else if( str1[MainIndx - i] == str1[MainIndx + tmp.length() + i - 1] && str1[MainIndx - i] == str2[MainIndx + tmp.length() + i - 1] && str1[MainIndx - i] == str2[MainIndx - i] )
            result++;
        else
            break;
    }
}
