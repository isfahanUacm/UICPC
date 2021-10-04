#include <bits/stdc++.h>
using namespace std;

#define MAX_n 100003
string arr[MAX_n];
vector<int> nex[MAX_n];int n, a, b;
bool pre[MAX_n];

void prints(int j){
    cout<<arr[j];
    for(auto v : nex[j])
        prints(v);
}

int main()
{
    cin>>n;
    for (int i = 1; i <= n; ++i)
        cin>>arr[i];
    for (int i = 1; i < n+1; ++i) {
        nex[i].clear();
    }
    fill_n(pre, n+1, false);
    for (int i = 0; i < n-1; ++i) {
        cin>>a>>b;
        pre[b]=true;
        nex[a].push_back(b);
    }
    int curr;
    for (int i = 1; i <= n; ++i) {
        if(!pre[i])
            curr = i;
    }
    prints(curr);
    cout<<endl;
    return 0;
}

