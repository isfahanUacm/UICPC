#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n , m ,h;
    cin >> n >> m >> h;
    int cnt = 1, q = 0;
    vector<vector<int>> v(n,vector<int>(m));
    vector<ll> res(n,0);
    for(int i = 0 ;i < n ;i ++)
    {
        for(int j = 0 ; j < m ; j ++)
        {
            cin >> v[i][j];
        }
        sort(v[i].begin(),v[i].end());

        ll t = 0 , sum = 0;
        int qp = 0;

        for(int j = 0 ; j < m ; j++)
        {
            sum += v[i][j];
            if(h < sum)
            {
                res[i] -= v[i][j];
                break;
            }

            res[i] += v[i][j] + t;
            t = res[i] ;


            if(i==0) {
                q++;
            }
            else {
                qp++;
            }

        }
        if((res[i] < res[0] && qp == q )|| qp>q)
        {
            cnt ++;
        }
    }
    cout << cnt << '\n' ;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
    cin >> n;
    while(n--)
        solve();

    return 0;
}