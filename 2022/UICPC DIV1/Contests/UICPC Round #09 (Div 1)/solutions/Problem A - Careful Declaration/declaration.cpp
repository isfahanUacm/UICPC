#include <bits/stdc++.h>
using namespace std;

// Careful Declaration

vector<string> split(const string& str, char delim){
    vector<string> cont;
    stringstream ss(str);
    string token;
    while(getline(ss, token, delim))
        cont.push_back(token);
    return cont;
}

vector<string> s, t;
string tmp;

int n, m, dp[2003][2003];

int main(){
    while(1){
        getline(cin, tmp);
        if(tmp == ".")
            break;
        tmp.pop_back(), tmp.pop_back();
        s = split(tmp, ' ');
        getline(cin, tmp);
        tmp.pop_back(), tmp.pop_back();
        t = split(tmp, ' ');
        n = s.size(), m = t.size();
        for(int i = n; i >= 0; i--)
            for(int j = m; j >= 0; j--){
                if(i == n && j == m)
                    dp[i][j] = 0;
                else if(i == n)
                    dp[i][j] = 1 + dp[i][j+1];
                else if(j == m)
                    dp[i][j] = 1 + dp[i+1][j];
                else if(s[i] == t[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1]);
            }
        int i = 0, j = 0;
        while(i < n || j < m){
            if(i == n)
                cout << t[j] << " ", j++;
            else if(j == m)
                cout << s[i] << " ", i++;
            else if(s[i] == t[j])
                cout << s[i] << " ", i++, j++;
            else if(dp[i+1][j] < dp[i][j+1])
                cout << s[i] << " ", i++;
            else if(dp[i][j+1] < dp[i+1][j])
                cout << t[j] << " ", j++;
            else if(s[i] < t[j])
                cout << s[i] << " ", i++;
            else
                cout << t[j] << " ", j++;
        }
        cout << "." << endl;
    }
}