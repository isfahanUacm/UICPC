#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int wash [1009][1009];

int main() {
    int n, m;
    cin >> n >> m;
    int time[1009];
    for (int i = 0; i < 1009; i++) {
        time[i] = 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cin>>wash[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j>0 && time[j-1] > time[j]){
                time[j] = time[j-1] + wash[i][j];
            }
            else time[j]+=wash[i][j];
        }
        cout<<time[m-1]<<" ";
    }
    // for(int i=0;i<m;i++){
    //     cout<<time[i]<<" ";
    // }
   return 0;
}