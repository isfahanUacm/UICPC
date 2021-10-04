#include <bits/stdc++.h>
using namespace std ;

map <char, int> alpha;
vector <char> c;
vector <string> s;
int ans = 0, n;
bool flag[10] = {false};

bool check(){
    vector<int> p(n);
    
    for (int i=0 ; i<n ; i++)
        if (alpha[s[i][0]] == 0) return false;

    for (int i=0 ; i<n ; i++){
        p[i] = 0;
        for (int j=0 ; j<s[i].size() ; j++)
            p[i] = p[i]*10 + alpha[s[i][j]];
    }

    int tmp = 0;
    for (int i=0 ; i<n-1 ; i++)
        tmp += p[i];
    
    if (tmp == p[n-1])
        return true;
    
    return false;
}

void solve(int index){
    if (index == c.size())
        if (check()) ans++;

    for (int i=0 ; i<10 ; i++){
        if (!flag[i]){
            flag[i] = true;
            
            alpha[c[index]] = i;
            
            solve(index+1);
            
            flag[i] = false;
        }
    }
}

int main(){
    cin >> n;
    s.resize(n);

    for (int i=0 ; i<n ; i++){
        cin >> s[i];
        for (int j=0 ; j<s[i].size() ; j++)
            alpha[s[i][j]] = -1;
    }
    
    for (auto ptr = alpha.begin() ; ptr != alpha.end() ; ptr++)
        c.push_back(ptr -> first);

    solve(0);
    
    cout << ans << endl;
    
    return 0;
}