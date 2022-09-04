#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
int n,m,x,y;
vector<int> K[1100];
vector<int> jjc[1100];
int S[1100];
int V[1100];
int ans[1100];
int C[1100];
int b=0;
int res=0;
void B()
{
    queue<int> q;
    S[1]=1;
    C[b++]=1;
    q.push(1);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        if(K[t].size()==0) {res++;S[t]=1;continue;}
        for(int i=0;i<K[t].size();i++)
        {
            if(S[K[t][i]]==1) continue;
            S[K[t][i]]=1;
            q.push(K[t][i]);
            C[b++]=K[t][i];
        }
    }
}
void D(int sx)
{
    if(V[sx]||S[sx]) return;
    if(K[sx].size()==0) {ans[sx]=1;return;}
    V[sx]=1;
    for(int i=0;i<K[sx].size();i++)
    {D(K[sx][i]);V[sx]=0;}
}

void get1(){
    cin >> n >> m;
}
void get2(){
    cin >> x >> y;
}
void dis(){
    cout << res;
}
int main()
{
    get1();
    int i=0;
    while(i<=n){ans[i]=0;S[i]=0;V[i]=0;i++;}
    i = 0;
    while(i<m)
    {
        get2();
        if(x<0){K[-x].push_back(y);}
        else{jjc[x].push_back(y);}
        i++;
    }
    B();
    i = 0;
    while(i<b)
    {   
        int j = 0;
        while(j<jjc[C[i]].size())
        {
            D(jjc[C[i]][j]);
            j++;
        }
        i++;
    }
    i = 1;
    while(i<=n){if(ans[i]==1) res++;i++;}
    dis();
    return 0;
}