#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;


int main() {
    long a;
    cin >> a;
    vector<long> arr1(a), arr2(a);
    for (long i = 0; i < a; ++i) {
        cin >> arr1[i];
    }

    for (long i = 0; i < a; ++i) {
        cin >> arr2[i];
    }
    unordered_map<long, long> map;
    long tot = 0;
    vector<long> ind;
    for (long i = 0; i< a; ++i) {
        map[arr1[i]]++;
        map[arr2[i]]--;


        bool  ok = true;
        for(auto a: map){
            if (a.second == 0){
                continue;
            }
            ok = false;
            break;
        }

        if (ok){
            ind.push_back(i);
            map = unordered_map<long, long>();
        }
    }

    long idx_c= 0;
    for (long i = 0; i < a; ++i) {
        cout << arr2[i] << " ";
        if(i == ind[idx_c] && idx_c != ind.size()-1) {
            cout <<"# ";
            idx_c++;
        }
    }
    return 0;
}