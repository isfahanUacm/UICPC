#include <bits/stdc++.h>
using namespace std;
int main() {

    int deps,bilds;
    cin>>deps>>bilds;
    map<int,int> pops;
    int* caps=new int [bilds];
    int* rents=new int [bilds];

    for (int i = 0; i < deps; ++i) {
        int pop;
        cin>>pop;
        pops[pop] = i;
    }
    for (int i = 0; i < bilds; ++i) {
        cin>>caps[i];
    }
    for (int i = 0; i < bilds; ++i) {
        cin>>rents[i];
    }

    pair<int,int> * arr = new pair<int,int>[bilds];
    for(int i = 0 ; i< bilds;i++){
        arr[i] = make_pair(caps[i],rents[i]);
    }

    bool imp = false;
    map<int,int> ans;


    for( map<int,int>::reverse_iterator i = pops.rbegin(); i != pops.rend();i++ ){
        int min ,k=0 ,minind = -1;
        while(k < bilds && arr[k].first < i->first ){
            k++;
        }
        if(k== bilds){
            imp = true;
            break;
        }

        min = arr[k].second;

        for (int j = 0 ; j < bilds;j++){
            if(arr[j].first >= i->first && arr[j].second <= min) {
                minind = j;
                min = arr[j].second;
            }
        }


        ans[(*i).second] = minind+1 ;
        arr[minind].first = 0;
        arr[minind].second = 0;

    }

    if(imp)
        cout << "impossible";
    else for(auto &i : ans)
        cout << i.second << ' ';

    return 0;
}
