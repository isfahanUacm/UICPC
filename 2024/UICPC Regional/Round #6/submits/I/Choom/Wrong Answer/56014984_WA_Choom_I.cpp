#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    int heros[t], villain[t], max_h = 0, max_v = 0;
    for (int i = 0; i < t; i++) {
        cin >> heros[i];
        max_h = max(max_h, heros[i]);
    }
    for (int i = 0; i < t; i++) {
        cin >> villain[i];
        max_v = max(max_v, villain[i]);
    }
    int days=0,temp=0,dayOne=0;
    bool equal=false;
    int i=0;
    for(i=0;i<t;++i)
    {
        if(heros[i]>villain[i])
            break;
        else if(heros[i]<villain[i] && !equal)
        {
            temp=villain[i]-heros[i];
            days+=temp;
            for(int j=0;j<t;++j)
                heros[j]+=temp;
            equal=true;
            if(i==0)
                dayOne=temp+1;
        }
        else if(heros[i]<villain[i] && equal)
        {
            temp=villain[i]-heros[i];
            if(days+temp>=dayOne)
                break;
//            else
//            {
//                days+=temp;
//                for(int j=0;j<t;++j)
//                    heros[i]+=temp;
//                equal= false;
//            }
        }
    }
    if(equal && i<t)
        cout<<dayOne;
    else
        cout<<days;
    return 0;
}
