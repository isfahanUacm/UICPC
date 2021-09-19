#include <bits/stdc++.h>
using namespace std;

int candidate_votes[10003];
bool eliminated[10003];
int v[103];
queue<int> ranking[103];
set<pair<int, int>> s;
int c, p, r, sum_all = 0, half_all = 0;

int main()
{
    cin >> c >> p;
    for (int i = 0; i < p; ++i) {
        cin >> v[i]; sum_all += v[i];
        for (int j = 0; j < c; ++j)
            cin >> r, ranking[i].push(r);
    }
    for (int i = 1; i <= c; ++i) {
        s.insert({0, i});
    }
    half_all = sum_all / 2;
    bool first = true;
    while(true){
        for (int i = 0; i < p; ++i) {
            bool flag = false;
            while(eliminated[ranking[i].front()])
                flag = true, ranking[i].pop();
            if(flag || first){
                s.erase({candidate_votes[ranking[i].front()], ranking[i].front()});
                candidate_votes[ranking[i].front()] += v[i];
                s.insert({candidate_votes[ranking[i].front()], ranking[i].front()});
            }
        }
        auto it = s.rbegin();
        if (it -> first > half_all){
            cout << it->second << endl;
            break;
        }
        eliminated[(s.begin())->second] = true;
        s.erase(s.begin());
        first = false;
    }
    return 0;
}

