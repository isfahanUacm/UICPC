#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define endl '\n';

struct pack{
    ll x,y;
};

double dist(vector<pack>c)
{
    double ans=LDBL_MAX;
    for (int i = 0; i < c.size(); ++i) {
        double dis=sqrt((144-c[i].x)*(144-c[i].x)+(84-c[i].y)*(84-c[i].y));
        if(dis<ans)
            ans=dis;
    }
    return ans;

}
double len(ll xa,ll ya)
{
    return sqrt((144-xa)*(144-xa)+(84-ya)*(84-ya));
}
double find(vector<pack>c)
{
    double ans=-1.0;
    for (int i = 0; i < c.size(); ++i) {
        double dis=sqrt((144-c[i].x)*(144-c[i].x)+(84-c[i].y)*(84-c[i].y));
        if(dis>ans)
            ans=dis;
    }
    return ans;
}
void solve() {
    ll red=0;//a
    ll yell=0;//b
    for (int i = 0; i < 10; ++i) {
         ll cr=0;
         ll cy=0;
         cin>>cr;
         vector<pack>a(cr);

        for (int j = 0; j < cr; ++j) {
            cin>>a[j].x>>a[j].y;
        }
        cin>>cy;
        vector<pack>b(cy);
        for (int j = 0; j < cy; ++j) {
            cin>>b[j].x>>b[j].y;
        }
        double mina= dist(a);
        double minb=dist(b);
        if(mina<minb)
        {
            for (int j = 0; j < a.size(); ++j) {
                if(len(a[j].x,a[j].y)<minb)
                    red++;
            }
        }
        else if(mina>minb){
            for (int j = 0; j < b.size(); ++j) {
                if(len(b[j].x,b[j].y)<mina)yell++;
            }
        }

    }
    cout<< red<<' '<<yell;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        if(t)cout<<'\n';
    }

}