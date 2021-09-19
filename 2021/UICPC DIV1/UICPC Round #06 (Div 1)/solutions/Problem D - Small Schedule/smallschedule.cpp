#include <bits/stdc++.h>
using namespace std;

long long int q, m, s, l;
priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

int main()
{
    cin >> q >> m >> s >> l;
    long long int time = 0;
    
    for (int i = 0; i < m; ++i) {
        if(l > 0){
            pq.push(q);
            time = q;
            l--;
        }
        else if(s > 0){
            pq.push(1);
            time = max(1LL, time);
            s--;
        }
        else{
            break;
        }
    }
    if(s+l == 0){
        cout << time << endl;
        return 0;
    }
    long long int toop;
    while(!pq.empty()){
        toop = pq.top(); pq.pop();
        if(l > 0){
            pq.push(toop + q);
            time = max(time, toop + q);
            l--;
        }
        else if(s > 0){
            pq.push(toop + 1);
            time = max(time, toop + 1);
            s--;
        }
        else{
            break;
        }
    }
    cout << time << endl;
    return 0;
}

