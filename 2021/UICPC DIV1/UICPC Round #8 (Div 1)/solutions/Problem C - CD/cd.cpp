#include<iostream>
#include<set>
#include<algorithm>
#include<unordered_set>
using namespace std;

int main()
{
    int n,m;
    while(true){
        cin>>n>>m;
        if(n==0&&m==0)
            break;

        unordered_set<int> jack;
        int c=0;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            jack.insert(a);
        }
        for(int i=0;i<m;i++){
            int a;
            cin >> a;
            if(jack.find(a)!=jack.end())
                c++;
        }
        cout<<c<<endl;

    }
    return 0;
}

