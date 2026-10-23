#include <bits/stdc++.h>
using namespace std;
#define float double

void solve() {
    int n;
    cin >> n;
    n *= 2;

    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    vector<vector<float>> m(n,vector<float>(n));
    vector<vector<float>> b(n,vector<float>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i==j || m[i][j] != 0)continue;
            if (arr[i].first > arr[j].first) {
                m[i][j] = (float(arr[i].second - arr[j].second) / float(arr[i].first - arr[j].first));
                if (m[i][j] == float(1.0 / 0.0))
                    b[i][j] = arr[i].first;
                else
                    b[i][j] = arr[i].second - (m[i][j] * arr[i].first);

                m[j][i] = m[i][j];
                b[j][i] = b[i][j];
            }
            else {
                m[i][j] = (float(arr[j].second - arr[i].second) / float(arr[j].first - arr[i].first));
                if (m[i][j] == float(1.0 / 0.0))
                    b[i][j] = arr[i].first;
                else
                    b[i][j] = arr[i].second - (m[i][j] * arr[i].first);

                m[j][i] = m[i][j];
                b[j][i] = b[i][j];
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    float sm;
    vector<bool> check(n,false);
    check[0] = true;
    list<float> bs;
    list<pair<int,int>> ans;

    auto rf = [&](int j, auto &&self) {
        if (j >= n) {
            return true;
        }

        if (check[j]) {
            return self(j+1,self);
        }

        for (int i = 1 ; i < n ; i++) {
            if ((!check[i]) && (i != j) && (m[i][j] == sm)) {

                ans.push_back(make_pair(i,j));
                bs.push_back(b[i][j]);

                check[i] = true;
                check[j] = true;

                if (self(j+1, self))
                    return true;

                ans.pop_back();
                bs.pop_back();
                check[i] = false;
                check[j] = false;
            }
        }
        return false;
    };

    for (int k =1; k < n; k++) {
        sm = m[0][k];
        check[k] = true;
        ans.push_back(make_pair(0,k));
        bs.push_back(b[0][k]);

        bool res = rf(1,rf);
        if (res) {
            map<float,list<pair<int,int>>> bb;
            auto aitr = ans.begin();
            for (auto &itr : bs) {
                bb[itr].push_back(*aitr);
                ++aitr;
            }
            if (bb.size() < n/2) {
                list<pair<int,int>> new_ans;

                for (auto &itr : bb) {
                    if (itr.second.size() > 1) {
                        vector<int> tmp;
                        tmp.reserve(itr.second.size() * 2);
                        for (auto &itr2 : itr.second) {
                            tmp.push_back(itr2.first);
                            tmp.push_back(itr2.second);
                        }
                        sort(tmp.begin(), tmp.end(),[&](auto a, auto b) {

                            if (arr[a].first == arr[b].first)
                                return arr[a].second < arr[b].second;

                            return arr[a].first < arr[b].first;

                        });
                        for (int l = 0; l < tmp.size(); l+= 2) {
                            new_ans.push_back(make_pair(tmp[l],tmp[l+1]));
                        }
                    }
                    else {
                        new_ans.push_back(itr.second.front());
                    }
                }
                for (auto &itr : new_ans) {
                    cout << itr.first + 1 << ' ' << itr.second + 1 << endl;
                }
            }
            else {
                for (auto &itr : ans) {
                    cout << itr.first + 1 << ' ' << itr.second + 1 << endl;
                }
            }
            return;
        }

        check[k] = false;
        ans.pop_back();
        bs.pop_back();
    }

    cout << -1;

}

int main() {

    int t=1;
    cin>>t;
    while(t--){
        solve();
        if (t)cout<<"\n";
    }

    return 0;
}