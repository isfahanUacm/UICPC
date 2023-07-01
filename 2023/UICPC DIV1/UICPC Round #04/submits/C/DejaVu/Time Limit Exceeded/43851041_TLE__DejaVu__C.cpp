#include <bits/stdc++.h>
using namespace std;
int digits(int i)
{
    int n=0;
    while(i>=1)
    {
        i=i/10;
        n++;
    }
    return n;
}
int convert(int digit, int n)
{
    int first=n;
    for(int i=0; i<digit-1; i++)
    {
        first=first/10;
    }

    n=n*10;
    int sec=first;
    for(int i=0; i<digit; i++)
    {
        sec=sec*10;
    }
    n=n-sec+first;
    return n;
}
int main()
{
    set<int> s;
    double n;
    cin>>n;

    for(int i=1; i<100000000; i++)
    {

        int digit=digits(i);
        int con = convert(digit,i);

        if(i*n==con)
        {

            if(digit==1)
            {

                s.insert(i);
                s.insert(i*10+i);
                s.insert(i*100+i*10+i);
                s.insert(i*1000+i*100+i*10+i);
                s.insert(i*10000+i*1000+i*100+i*10+i);
                s.insert(i*100000+i*10000+i*1000+i*100+i*10+i);
                s.insert(i*1000000+i*100000+i*10000+i*1000+i*100+i*10+i);
                s.insert(i*10000000+i*1000000+i*100000+i*10000+i*1000+i*100+i*10+i);

            }
            else if(digit==2)
            {

                s.insert(i);
                s.insert(i*100+i);
                s.insert(i*10000+i*100+i);
                s.insert(i*1000000+i*10000+i*100+i);
            }
            else if(digit==3)
            {
                s.insert(i);
                s.insert(i*1000+i);

            }
            else if(digit==4)
            {
                s.insert(i);
                s.insert(i*10000+i);
            }
            else if(digit==5){
                s.insert(i);
            }
            else if(digit==6){
                s.insert(i);
            }
            else if(digit==7){
                s.insert(i);
            }
            else if(digit==8){
                s.insert(i);
            }
        }

    }
    set<int>::iterator itr;

    // iterator itr loops from begin() till end()
    for (itr = s.begin(); itr != s.end();
            itr++)
        cout << *itr <<endl;

    if(s.empty()){
        cout<<"No solution";
    }

    return 0;
}
