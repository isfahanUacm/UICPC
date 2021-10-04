#include <bits/stdc++.h>
using namespace std;

// Haiku

vector<string> split(const string& str, char delim){
    vector<string> cont;
    stringstream ss(str);
    string token;
    while(getline(ss, token, delim))
        cont.push_back(token);
    return cont;
}

string tmp;
set<string> dict;
vector<string> words;
int dp[103][103][13];

bool cdp(int word, int index, int need){
    if(dp[word][index][need] != -1)
        return dp[word][index][need];
    if(word == words.size())
        return dp[word][index][need] = !need;
    if(!need)
        return dp[word][index][need] = 0;
    if(dict.find(words[word].substr(index)) != dict.end() && cdp(word + 1, 0, need - 1))
        return dp[word][index][need] = 1;
    for(int cut = index + 1; cut < words[word].size(); cut++)
        if(dict.find(words[word].substr(index, cut - index)) != dict.end() && cdp(word, cut, need - 1))
            return dp[word][index][need] = 1;
    return dp[word][index][need] = 0;
}

bool solve(int need){
    getline(cin, tmp);
    words = split(tmp, ' ');
    for(int i = 0; i < 103; i++)
        for(int j = 0; j < 103; j++)
            for(int k = 0; k < 13; k++)
                dp[i][j][k] = -1;
    return cdp(0, 0, need);
}

int main(){
    int s;
    cin >> s;
    while(s--)
        cin >> tmp, dict.insert(tmp);
    cin.ignore();
    if(solve(5) && solve(7) && solve(5))
        cout << "haiku" << endl;
    else
        cout << "come back next year" << endl;
}