#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;
const int maxn = 2e5 + 7 ;
priority_queue<ll> q ;
struct node
{
    int t , h ;
    bool operator < (const node &b )
    {
       return h <b.h ;
    }
}a[maxn] ;

int main()
{
    int n ;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++) cin >> a[i].t >>a[i].h ;
        sort(a+1,a+1+n);
    ll sum = 0 ;
    for ( int i = 1 ; i <= n ; i ++ )
    {
        if ( sum +a[i].t <= a[i].h)
        {
            q.push(a[i].t);
            sum += a[i].t  ;
        }
        else
        {
            if ( !q.empty()&&q.top()>a[i].t)
            {
                sum -= q.top() ;
                q.pop();
                q.push(a[i].t);
                sum += a[i].t ;
            }
        }



    }
     cout << q.size() <<endl;
    return   0 ;
}
