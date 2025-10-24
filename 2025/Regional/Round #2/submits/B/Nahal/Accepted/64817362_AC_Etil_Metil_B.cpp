#include<iostream>
#include<cmath>
#include <sstream>
#include<string>
using namespace std;


int main()
{



    int n,p;
    cin>>n>>p;

    string group[n][2*p];
    int s[p];
    int t[p];
    int f[p];

   int count1=0,count2=0,count3=0;


    int ali=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2*p; ++j) {
            cin>>group[i][j];
        }

    }



    ali=0;
    for (int j= 0; j <(2*p)-1 ; j+=2) {
        count1=0;
        count2=0;
        count3=0;
        for (int i = 0; i< n;i++) {
            if(group[i][j]=="+"){
                count1++;
            }
            if(stoi(group[i][j+1])>0 || group[i][j]=="+"){
                count2++;
            }
            count3+=(stoi(group[i][j+1]));
        }
        s[ali]=count1;
        t[ali]=count2;
        f[ali]=count3;
        ali++;
    }

    for (int i = 0; i < p; ++i) {
        cout<<s[i]<<" " <<t[i]<<" "<<f[i]<<endl;
    }









    return 0;
}