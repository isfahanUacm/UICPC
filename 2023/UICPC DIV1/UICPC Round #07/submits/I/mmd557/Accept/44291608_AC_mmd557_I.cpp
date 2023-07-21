#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;


int main() {
    long a, c;
    cin >> a >> c;
    long sum = 0, s=0, e=0;
    vector<long> arr(a);
    vector<long> start(a,0);
    vector<long> end(a,0);

    for (int i = 0; i < a; ++i) {
        cin >> arr[i];
    }

    long inside_s=arr[0];
    while (true) {
        if (e >= s){
            start[s]++;
            end[e]++;
         }

        if (e + 1 == a) {
            inside_s -= arr[s];
            s++;
        } else if (inside_s + arr[e+1] > c) {
            inside_s -= arr[s];
            s++;
        } else{
            e++;
            inside_s += arr[e];
        }

        if (s == a && e == a-1)
            break;
    }
    long ins = 0;
    for (int i = 0; i < a; ++i) {
        ins += start[i];
        cout << ins << endl;
        ins -= end[i];
    }
    return 0;
}