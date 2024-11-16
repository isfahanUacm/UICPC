#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> fibo(35);
void create()
{
    int n = 29;
    fibo[0]=1;
    fibo[1] = 2;
    for(int i=0; i<n; i++)
    {
        fibo[i+2] = fibo[i] + fibo[i+1];
    }
}

void solve()
{
    vector<vector<int>> num_ind_i;
    vector<int> ind_only;
    vector<int> num_only;
    int n; cin >> n;
    vector<int> cnt;
    for(int i=1; i<=n; i++)
    {
        int x; cin >> x;
        num_only.push_back(x);
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
    vector<int> num_only_sort = num_only;
    sort(num_only_sort.begin(), num_only_sort.end());
    for(int i=0; i<num_only_sort.size()-1; i++)
    {
        if(num_only_sort[i]+1 == num_only_sort[i+1])
        {
            int in1, in2;
            for(int j=0; j<num_only.size(); j++)
            {
                if(num_only[j] == num_only_sort[i])
                    in1 = j+1;
                if(num_only[j] == num_only_sort[i+1])
                    in2 = j+1;
            }
            cout << in1 << " " << in2;
            return;
        }
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
//    cout << flush;

    solve();

    return 0;
}
