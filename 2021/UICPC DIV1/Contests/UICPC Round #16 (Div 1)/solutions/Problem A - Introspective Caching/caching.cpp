#include <bits/stdc++.h>
using namespace std;

vector<queue<int>> v;
set<int> m;
set<int, greater<int>> s;
int c, n, a, b, res, d;
int arr[1000003];

int main()
{
    cin>>c>>n>>a;
    res = 0;d=100001;
    v.resize(n, queue<int>());m.clear();
    for (int i = 0; i < a; ++i) {
        cin>>b;
        arr[i] = b;
        v[b].push(i);
    }
    for (int i = 0; i < a; ++i) {
        if(m.size()<c){
            auto f = m.find(arr[i]);
            if(f!=m.end() && *f == arr[i]){
                s.erase(s.find(v[arr[i]].front()));
                v[arr[i]].pop();
                if(v[arr[i]].size()==0)
                    s.insert(d),v[arr[i]].push(d), arr[d] = arr[i], d++;
                else
                    s.insert(v[arr[i]].front());
//                cout<<"rep"<<i<<" "<<arr[i]<<" "<<res<<endl;
                continue;
            }
            v[arr[i]].pop();
            m.insert(arr[i]);
            if(v[arr[i]].size()==0)
                s.insert(d),v[arr[i]].push(d), arr[d]=arr[i], d++;
            else
                s.insert(v[arr[i]].front());
            res++;
//            cout<<"<c"<<i<<" "<<arr[i]<<" "<<res<<endl;
            continue;
        }
        auto it = m.find(arr[i]);
        if(it != m.end() && *it == arr[i]){
            s.erase(s.find(v[arr[i]].front()));
            v[arr[i]].pop();
            if(v[arr[i]].size()==0)
                s.insert(d),v[arr[i]].push(d), arr[d]=arr[i], d++;
            else
                s.insert(v[arr[i]].front());
        }
        else{
            m.erase(m.find(arr[*s.begin()]));
            s.erase(s.begin());
            v[arr[i]].pop();
            m.insert(arr[i]);
            if(v[arr[i]].size()==0)
                s.insert(d),v[arr[i]].push(d), arr[d] = arr[i], d++;
            else
                s.insert(v[arr[i]].front());
            res++;
        }
//        cout<<i<<" "<<arr[i]<<" "<<res<<endl;
//        cout<<"mmm: ";
//        for (auto j : m) {
//            cout<<j<<" ";
//        }cout<<endl;
//        cout<<"sss: ";
//        for (auto j : s) {
//            cout<<j<<" ";
//        }cout<<endl;
    }
    cout<<res<<endl;
    return 0;
}
