#include <bits/stdc++.h>
using namespace std;

// Hot Springs

const int maxn = 1e5 + 3;

int n, t[maxn], ans[maxn];

inline bool validate(){
    for(int i = 1; i < n-1; i++)
        if (abs(ans[i] - ans[i-1]) > abs(ans[i] - ans[i+1]))
            return false;
    return true;
}

inline void produce1(int start){
    int ptr = 0;
    int lptr = start-1, rptr = start+1;
    ans[ptr++] = t[start];
    while (true) {
        ans[ptr++] = t[rptr++];
        if (ptr == n)
            break;
        ans[ptr++] = t[lptr--];
        if (ptr == n)
            break;
    } 
}

inline void produce2(int start){
    int ptr = 0;
    int lptr = start-1, rptr = start+1;
    ans[ptr++] = t[start];
    while (true) {
        ans[ptr++] = t[lptr--];
        if (ptr == n)
            break;
        ans[ptr++] = t[rptr++];
        if (ptr == n)
            break;
    } 
}

inline void print() {
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    sort(t, t + n);
    if (n % 2) {
        produce1(n / 2);
        if (validate()) {
            print();
            return 0;
        }
        produce2(n / 2);
        if (validate()) {
            print();
            return 0;
        }
    }
    else {
        produce1(n / 2 - 1);
        if (validate()) {
            print();
            return 0;
        }
        produce2(n / 2);
        if (validate()) {
            print();
            return 0;
        }
    }
    cout << "impossible" << endl;
}