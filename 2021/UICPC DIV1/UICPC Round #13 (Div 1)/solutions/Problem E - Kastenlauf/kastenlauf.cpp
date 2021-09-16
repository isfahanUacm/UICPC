#include <bits/stdc++.h>
using namespace std;

#define MAX_n 103
int t, n;
int matAdj[MAX_n][MAX_n];
pair<int, int> points[MAX_n];

int calc(int i, int j){
    return abs(points[i].first-points[j].first) + abs(points[i].second-points[j].second);
}

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for (int i = 0; i < n+2; ++i)
            for (int j = 0; j < n+2; ++j)
                matAdj[i][j]=(i==j);
        for (int i = 0; i < n+2; ++i)
            cin>>points[i].first>>points[i].second;
        for (int i = 0; i < n+2; ++i)
            for (int j = 0; j < n+2; ++j)
                matAdj[i][j]= (calc(i, j)<=1000);
        for (int k = 0; k < n+2; ++k)
            for (int i = 0; i < n+2; ++i)
                for (int j = 0; j < n+2; ++j)
                    matAdj[i][j] |= matAdj[i][k] & matAdj[k][j];
        cout<<((matAdj[0][n+1])?"happy":"sad")<<endl;
    }
    return 0;
}

