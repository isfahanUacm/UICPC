#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;
vector<pair<int,int>> moose_list;
int k, n, y, p, karlp;

int main()
{
    cin >> k >> n;
    cin >> y >> p; karlp = p;
    moose_list.push_back({y, p});
    for (int i = 0; i < n+k-2; ++i) {
        cin >> y >> p;
        moose_list.push_back({y, p});
    }
    sort(moose_list.begin(), moose_list.end());
    for (int i = 0; i < k; ++i)
        pq.push(moose_list[i].second);
    int winnerp = pq.top(); pq.pop();
    if(winnerp == karlp){
        cout << 2011 << endl;
        return 0;
    }
    int curyear = 2012;
    for (int i = k; i < moose_list.size(); ++i) {
        while(!pq.empty() && curyear != moose_list[i].first){
            winnerp = pq.top(); pq.pop();
            if(winnerp == karlp){
                cout << curyear << endl;
                return 0;
            }
            curyear++;
        }
        curyear = moose_list[i].first;
        pq.push(moose_list[i].second);
        winnerp = pq.top(); pq.pop();
        if(winnerp == karlp){
            cout << curyear << endl;
            return 0;
        }
        curyear++;
    }
    cout << "unknown" << endl;
    return 0;
}

