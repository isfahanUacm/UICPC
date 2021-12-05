#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b){
    if (a.first == b.first) return a.second.size() > b.second.size();
    return a.first<b.first;
}
int main(){
    map<string, string> m;
    vector<string> v;
    m["at"] = '@'; m["and"] = '&'; m["one"] = '1'; m["won"] = '1'; m["too"] = '2'; m["to"] = '2'; m["two"] = '2';
    m["for"] = '4'; m["four"] = '4'; m["bea"] = 'b'; m["bee"] = 'b'; m["be"] = 'b'; m["sea"] = 'c'; m["see"] = 'c';
    m["eye"] = 'i'; m["oh"] = 'o'; m["owe"] = 'o'; m["are"] = 'r'; m["you"] = 'u'; m["why"] = 'y';
    m["At"] = '@'; m["And"] = '&'; m["One"] = '1'; m["Won"] = '1'; m["To"] = '2'; m["Too"] = '2'; m["Two"] = '2';
    m["For"] = '4'; m["Four"] = '4'; m["Bea"] = 'B'; m["Bee"] = 'B'; m["Be"] = 'B'; m["Sea"] = 'C'; m["See"] = 'C';
    m["Eye"] = 'I'; m["Oh"] = 'O'; m["Owe"] = 'O'; m["Are"] = 'R'; m["You"] = 'U'; m["Why"] = 'Y';

    for(auto e : m){
      v.push_back(e.first);
    }

    int n;
    string s, ss;
    vector<pair<int, string>> poses;
    cin>>n;
    getline(cin, s);
    for (int i = 0; i < n; i++)
    {
        poses.clear();
        getline(cin, s);
        ss = s;
        for (string ks : v){
            int pos = s.find(ks, 0);
            while(pos != string::npos)
            {
                poses.push_back({pos, ks});
                pos = s.find(ks,pos+1);
            }
        }
        sort(poses.begin(), poses.end(), cmp);
        int preind = -1;
        string prestr = " ";
        int offset = 0;
        for (auto p:poses){
            if (preind + prestr.size() > p.first) continue;
            ss.replace(p.first-offset, p.second.size(), m[p.second]);
            preind = p.first; prestr = p.second;
            offset += p.second.size()-1;
        }
        cout<<ss<<endl;
    }
    
}