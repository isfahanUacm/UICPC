#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[105];
    fgets(str , 105 , stdin);
    int len = strlen(str);
    char String[105][105];
    int Counter = 0;
    int t = 0;
     for(int i=0;i<len;i++)
     {
        if(str[i]>='a'&&str[i]<='z')
       {
               str[i]=str[i]-'a'+'A';
       }
       }
    for(int i=0;i<len;i++)
    {
        if(str[i]==' '||str[i]=='\0')
        {
            String[Counter][t]='\0';
            t = 0;
            Counter++;
        }
        else
        {
            String[Counter][t] = str[i];
            t++;
        }
    }

    for(int i=0;i<Counter;i++)
    {
        for(int j=i+1;j<=Counter;j++)
        {
            if(strcmp(String[i],String[j])==0)
            {
               cout<< "no\n";
                return 0;
            }
        }
    }
    cout << "yes\n"  ;
    return 0;
}
