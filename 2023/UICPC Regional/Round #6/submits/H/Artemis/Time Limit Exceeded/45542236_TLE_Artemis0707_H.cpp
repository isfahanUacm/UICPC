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

    sort(ans.begin(), ans.end());
    float mid;
    if(ans.size() % 2 == 0)
        mid = (ans[ans.size()/2 - 1] + ans[ans.size()/2]) / 2;
    else
        mid = ans[ans.size()/2];

    printf("%.6f\n", mid);
    return 0;
}
