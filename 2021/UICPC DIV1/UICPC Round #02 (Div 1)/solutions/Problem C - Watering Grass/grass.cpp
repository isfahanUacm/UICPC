#include <bits/stdc++.h>
using namespace std;

pair<double, double> p[10003];

int comp(pair<double, double> p1, pair<double, double> p2){
    if(p1.first<p2.first)
        return 1;
    else if(p1.first==p2.first)
        return p1.second>p2.second;
    return 0;
//    return p1.first<p2.first;
}

int main()
{
    int n;
    double l , w, x, r;bool flag = false;
    while(cin>>n>>l>>w){
        for (int i = 0; i < n; ++i) {
            cin>>x>>r;
            p[i].first = (r*r-(w*w)/4>=0)?x-sqrt(r*r - (w/2)*(w/2)):-1;
            p[i].second = (r*r-(w*w)/4>=0)?x+sqrt(r*r - (w/2)*(w/2)):-1;
        }
        sort(p, p+n, comp);
//        for (int i = 0; i < n; ++i) {
//            cout<<"("<<p[i].first<<","<<p[i].second<<")"<<" ";
//        }cout<<endl;
        int i=0, res=0;
        double li= 0, tmp;flag=false;
        while(i<n && li<l){
            if(p[i].second<=li){
                i++;
                continue;
            }
            if(p[i].first>li){
                flag = true;
                break;
            }
            tmp = li;
            while(i<n && p[i].first<=li){
                tmp = max(tmp, p[i++].second);
            }
            li = tmp;
            res++;
        }
        if(li<l || flag){
            cout<<-1<<endl;
            continue;
        }
        cout<<res<<endl;
        
    }
    return 0;
}
/*
10 6 37
20 4
19 20
19 2
8 4
7 19
7 14
3 17
1 19
18 1
15 19
*/
