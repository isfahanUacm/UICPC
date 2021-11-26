#include <bits/stdc++.h>
using namespace std;

// Errands

int n;
pair<string, pair<double, double>> locs[103];
map<string, int> ntoi;

double floyd[103][103];

double dist(pair<double, double> p1, pair<double, double> p2){
    double deltax = p1.first - p2.first;
    double deltay = p1.second - p2.second;
    return sqrt(deltax * deltax + deltay * deltay);
}

string line, name;
int p;
int places[13];

double dp[1<<13][13];
int trace[1<<13][13];

vector<string> path;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> locs[i].first >> locs[i].second.first >> locs[i].second.second;
    for(int i = 0; i < n; i++){
        if(locs[i].first == "work")
            swap(locs[i], locs[0]);
        else if(locs[i].first == "home")
            swap(locs[i], locs[n-1]);
    }
    for(int i = 1; i < n-1; i++)
        ntoi[locs[i].first] = i;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            floyd[i][j] = dist(locs[i].second, locs[j].second);
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
    getline(cin, line);
    while(getline(cin, line)){
        p = 0;
        stringstream ss(line);
        while(ss >> name)
            places[p++] = ntoi[name];
        places[p++] = n-1;
        for(int mask = 1; mask < (1<<p); mask++)
            for(int node = 0; node < p; node++){
                if(mask == 1<<node){
                    dp[mask][node] = floyd[0][places[node]];
                    trace[mask][node] = -1;
                }
                else if(mask & (1<<node)){
                    int ans = INT_MAX, par;
                    for(int prevy = 0; prevy < p; prevy++)
                        if(prevy != node && (mask & (1<<prevy))){
                            double curr = dp[mask-(1<<node)][prevy] + floyd[places[prevy]][places[node]];
                            if(curr < ans){
                                ans = curr;
                                par = prevy; 
                            }
                        }
                    dp[mask][node] = ans;
                    trace[mask][node] = par;
                }
            }
        path.clear();
        int mask = (1<<p) - 1, it = p-1;
        while(trace[mask][it] != -1){
            int p = trace[mask][it];
            path.push_back(locs[places[p]].first);
            mask -= 1<<it;
            it = p;
        }
        for(int i = path.size()-1; i >= 0; i--)
            cout << path[i] << " ";
        cout << endl;
    }
}