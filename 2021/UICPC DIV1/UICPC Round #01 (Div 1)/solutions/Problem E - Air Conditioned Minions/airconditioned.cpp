#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> f, pair<int, int> s){
    return f.second<s.second;
}

pair<int, int> minions[103];
int n;
int main()
{
    cin>>n;
    for (int i = 0; i < n; ++i)
        cin>>minions[i].first>>minions[i].second;
    sort(minions, minions+n, cmp);
    int curr = minions[0].second;
    int tmp = 1, res = 0;
    while(tmp<n){
        while(curr>=minions[tmp].first)
            tmp++;
        curr = minions[tmp].second;
        res++;
    }
    cout<<res<<endl;
    return 0;
}

