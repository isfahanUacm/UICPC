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

int main(void)
{
     string str1;
     string str2 ;
     string tmp , tmpStr1;
     int result = 0;
     cin >> str1 >> str2;
     string str1Reverse = str1;
     reverse(str1Reverse.begin() , str1Reverse.end());




     if(str1.length() == 1);

     else
     {
         for(int j = 0 ; j < str1.length() ; j++)
             for(int i = 2 ; i < str1.length() + 1 ; i++)
             {
                 if(i + j < 0 || i + j > str1.length())
                     break;
                 tmpStr1 = str1;
                 tmp = str1.substr(j , i);
                 string tmp2 = tmp;
                 reverse(tmp.begin() , tmp.end());
                 replace(tmpStr1 , tmp2 , tmp);
                 if(tmpStr1 == str2)
                     result++;
             }
     }

     cout << result;
}
