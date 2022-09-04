#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char str[105];
    gets(str);
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            str[i]=str[i]-'a'+'A';
        }
    }

    char s[105][105];
    int cnt = 0;
    int t = 0;
    for(int i=0;i<len;i++)
    {
        if(str[i]==' '||str[i]=='\0')
        {
            s[cnt][t]='\0';
            t = 0;
            cnt++;
        }
        else
        {
            s[cnt][t] = str[i];
            t++;
        }
    }

    for(int i=0;i<cnt;i++)
    {
        for(int j=i+1;j<=cnt;j++)
        {
            if(strcmp(s[i],s[j])==0)
            {
               cout <<"no" << endl;
                return 0;
            }
        }
    }
    cout << "yes\n" ;
}
