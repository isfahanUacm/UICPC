#include <bits/stdc++.h>
using namespace std;

// Abandoned Animal

const int maxk = 1e5 + 3;

int n, k, m, cnt = 0, shopping_list[maxk];
unordered_map<string, int> id;
vector<int> shops[maxk], least_lexicographical_answer, most_lexicographical_answer; 

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int shop;
        string item;
        cin >> shop >> item;
        if(id.find(item) == id.end())
            id[item] = cnt++;
        shops[id[item]].push_back(shop);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        string item;
        cin >> item;
        shopping_list[i] = id[item];
    }
    for(int i = 0; i < cnt; i++)
        sort(shops[i].begin(), shops[i].end());
    int min_pointer = 0;
    for(int i = 0; i < m; i++){
        auto it = lower_bound(shops[shopping_list[i]].begin(), shops[shopping_list[i]].end(), min_pointer);
        if(it == shops[shopping_list[i]].end()){
            cout << "impossible" << endl;
            return 0;
        }
        least_lexicographical_answer.push_back(*it);
        min_pointer = *it;
    }
    int max_pointer = n;
    for(int i = m-1; i >= 0; i--){
        auto it = prev(upper_bound(shops[shopping_list[i]].begin(), shops[shopping_list[i]].end(), max_pointer));
        most_lexicographical_answer.push_back(*it);
        max_pointer = *it;
    }
    reverse(most_lexicographical_answer.begin(), most_lexicographical_answer.end());
    if(least_lexicographical_answer == most_lexicographical_answer)
        cout << "unique" << endl;
    else
        cout << "ambiguous" << endl;
}