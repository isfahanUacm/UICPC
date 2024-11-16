#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n;
    cin >> n;

    multimap<long int,int> arr;
    for(int i = 0 ; i < n ; i++){
        long int tmp;
        cin >> tmp;
        arr.insert(make_pair(tmp,i));
    }

    int lst=1 , crnt =1;

    multimap<long int, int>::iterator i = arr.begin();
    pair<long int,int> last = make_pair(i->first,i->second);
    ++i;

    for(i;i != arr.end();++i ){
        while(i->first > crnt){
            long int tmp = crnt;
            crnt += lst;
            lst = tmp;
        }
        if(i->first == crnt && last.first == lst){
            cout << last.second+1 << ' ' << i->second+1;
            return 0;
        }
        if(last.first != lst)
            last = make_pair(i->first,i->second);
    }

    cout << "impossible";


    return 0;
}