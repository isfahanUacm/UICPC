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
    unordered_map<long, long> map1;
    unordered_map<long, long> map2;
    vector<long> ind;
    long s1=0,s2=0;
    long sum=0;
    for (long i = 0; i< a; ++i) {
        bool was_eq1 = false;
        bool was_eq2 = false;
        if (map1[arr1[i]] == map2[arr1[i]]) {
            was_eq1 = true;
        }
        if (map1[arr2[i]] == map2[arr2[i]]) {
            was_eq2 = true;
        }

        map1[arr1[i]]++;
        map2[arr2[i]]++;

        bool is_eq1 = false;
        bool is_eq2 = false;

        if (map1[arr1[i]] == map2[arr1[i]]) {
            is_eq1 = true;
        }
        if (map1[arr2[i]] == map2[arr2[i]]) {
            is_eq2 = true;
        }

        if (was_eq1 && ! is_eq1) {
            sum++;
        }
        if (was_eq2 && ! is_eq2) {
            sum++;
        }

        if (!was_eq1 && is_eq1) {
            sum--;
        }
        if (!was_eq2 && is_eq2) {
            sum--;
        }
        if (sum == 0){
            ind.push_back(i);
            map1 = unordered_map<long, long>();
            map2 = unordered_map<long, long>();
        }
    }

    long idx_c= 0;
    for (long i = 0; i < a; ++i) {
        cout << arr2[i] << " ";
        if (ind.size() == 0)
            continue;
        if(i == ind[idx_c] && idx_c != ind.size()-1) {
            cout <<"# ";
            idx_c++;
        }
    }
    return 0;
}