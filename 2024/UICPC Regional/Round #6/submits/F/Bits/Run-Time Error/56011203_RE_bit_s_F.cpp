#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> fibo;
void create()
{
    int n = 29;
    fibo.push_back(1);
    fibo.push_back(2);
    for(int i=0; i<n; i++)
    {
        fibo.push_back(fibo[i] + fibo[i+1]);
    }
}

void solve()
{
    vector<vector<int>> num_ind_i;
    vector<int> ind_only;
    int n; cin >> n;
    vector<int> cnt;
    for(int i=1; i<=n; i++)
    {
        int x; cin >> x;
        if(x == 1)
            cnt.push_back(i);
        auto itr = std::find(fibo.begin(), fibo.end(), x);
//        cout << *itr << endl;
        if(itr != fibo.end())
        {
//            cout << "here";
            int ind = itr-fibo.begin();
            vector<int> tmp = {x, ind, i};
            num_ind_i.push_back(tmp);
            ind_only.push_back(ind);
        }
    }
    if(cnt.size() > 1)
    {
        cout << cnt[0] << ' ' << cnt[1];
        return;
    }



//    for(auto x : num_ind_i)
//    {
//        for(auto y : x)
//            cout << y << " ";
//        cout << endl;
//    }



    bool flag = true;

    sort(ind_only.begin(), ind_only.end());
    for(int i=0; i<ind_only.size()-1; i++)
    {
        vector<int> ans(2);
        if(ind_only[i+1] - ind_only[i] == 1)
        {
            for(auto x : num_ind_i)
            {
                if(x[1] == ind_only[i])
                    ans[0] = x[2];
                if(x[1] == ind_only[i+1])
                    ans[1] = x[2];
            }
            cout << ans[0] << " " << ans[1];
            flag = false;
            break;
        }
    }

    if(flag) cout << "impossible";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    create();


//    for(auto x : fibo)
//        cout << x << " ";

    solve();

    return 0;
}
