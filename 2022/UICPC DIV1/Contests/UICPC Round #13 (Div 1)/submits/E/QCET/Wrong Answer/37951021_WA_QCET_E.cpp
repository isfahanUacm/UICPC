#include <iostream>
#include <vector>
using namespace std ;




int main()
{
    int count = 0;
    vector<int>index;
    int number;
    cin>>number;
    string *a = new string [number];
    for (int i =0 ; i <number;i++){
        cin>>a[i];
        if (a[i] =="O")
        {
            index.push_back(i);
        }
    }
    while(index.size()!=0)
    {
        int i = index[index.size()-1];
        a[i]= "Z";
        index.pop_back();
        for (int j = i+1;j<number;j++){
            a[j]="O";
            index.push_back(j);
        }
        count++;


    }
    cout<<count<<endl;
    return 0 ;
}
