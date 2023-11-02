#include<bits/stdc++.h>
using namespace std;

int s[141][122], t_sum[141][122];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w, a, b;
    cin>>h>>w>>a>>b;
    for(int i=1;i<=h;i++) {
        for(int j=1;j<=w;j++) {
            cin >> s[i][j];
            t_sum[i][j] = s[i][j]+t_sum[i-1][j]+t_sum[i][j-1]-t_sum[i-1][j-1];
        }
    }

    vector<float> ans;
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            for(int k=i; k<=h; k++) {
                for(int l=j; l<=w; l++) {
                    int area = (k-i+1) * (l-j+1);
                    if(area < a || area > b) 
                        continue;
                    int sum = t_sum[k][l]-t_sum[i-1][l]-t_sum[k][j-1]+t_sum[i-1][j-1];
                    ans.push_back((float)sum/area);
                }
            }
        }
    }

    if (ans.size() % 2 == 0) {
        nth_element(ans.begin(), ans.begin() + ans.size() / 2 - 1, ans.end());
        double first = ans[ans.size()/2 - 1];

        nth_element(ans.begin(), ans.begin() + ans.size() / 2, ans.end());
        double second = ans[ans.size()/2];

        printf("%.5f\n", (first + second) / 2);
    }
    else {
        nth_element(ans.begin(), ans.begin() + ans.size() / 2 - 1, ans.end());
        printf("%.5f\n", ans[ans.size() / 2]);
    }
    return 0;
}
