#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int reds=0;
    cin>>n;
    string* arr=new string [n];
    list<int> s;

    for (int i = 0; i < n; ++i) {
        cin>>arr[i];

        if(arr[i]=="black")
            s.push_back(7);

        else if(arr[i]=="pink")
            s.push_back(6);

        else if(arr[i]=="blue")
            s.push_back(5);

        else if(arr[i]=="brown")
            s.push_back(4);

        else if(arr[i]=="green")
            s.push_back(3);

        else if(arr[i]=="yellow")
            s.push_back(2);

        else
        {

            reds++;
        }
    }

    int max = 0;
    int score = 0;

    for(auto &i : s){
        score += i;
        if(i > max)
            max = i;
    }

    score += (reds * max) + reds ;

    if(max == 0)
        score =1;

    cout<<score;



   return 0;
}