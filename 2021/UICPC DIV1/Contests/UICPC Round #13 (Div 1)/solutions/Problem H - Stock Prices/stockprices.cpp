#include <bits/stdc++.h>
using namespace std;

string ordertype, _;
int x, y, n ,t, s;
pair<int, int> selltop, buytop;

int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        priority_queue<pair<int, int>> buypq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sellpq;
        s = -1;
        for (int i = 0; i < n; ++i) {
            cin >> ordertype >> x >> _ >> _ >> y;
            
            if (ordertype == "buy"){
                while(!sellpq.empty() && y >= sellpq.top().first){
                    selltop = sellpq.top();sellpq.pop();
                    s = selltop.first;
                    if (selltop.second < x){
                        x -= selltop.second;
                    }
                    else if (selltop.second > x){
                        sellpq.push({selltop.first, selltop.second - x});
                        x = 0;
                        break;
                    }
                    else{
                        x = 0;
                        break;
                    }
                }   
                if(x){
                    buypq.push({y, x});
                }
            }
            else{
                while(!buypq.empty() && y <= buypq.top().first){
                    s = y;
                    buytop = buypq.top();buypq.pop();
                    if (buytop.second < x){
                        x -= buytop.second;
                    }
                    else if (buytop.second > x){
                        buypq.push({buytop.first, buytop.second - x});
                        x = 0;
                        break;
                    }
                    else{
                        x = 0;
                        break;
                    }
                }
                if(x){
                    sellpq.push({y, x});
                }
            }
            cout << ((sellpq.empty()) ? "-" : to_string(sellpq.top().first)) << " " << ((buypq.empty()) ? "-" : to_string(buypq.top().first)) << " " << ((s == -1) ? "-" : to_string(s)) << endl;
        }
    }
    return 0;
}

