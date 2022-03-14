#include <bits/stdc++.h>
using namespace std;

// ACM Contest Scoring

set<char> solved;
map<char, int> penalty;

int main(){
    int m;
    char p;
    string verdict;
    int ans = 0;
    while(1){
        cin >> m;
        if(m == -1)
            break;
        cin >> p >> verdict;
        if(solved.find(p) == solved.end()){
            if(verdict == "right"){
                solved.insert(p);
                ans += m + penalty[p];
            }
            else
                penalty[p] += 20;
        }
    }
    cout << solved.size() << " " << ans << endl;
}