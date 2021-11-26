#include<bits/stdc++.h>
using namespace std;

class FenwickTree { // Notice: it is 1-based fenwick-tree.
    private: 
    vector<long long int> ft;
    public:
    FenwickTree(int n){
        ft.assign(n + 1, 0); // init n + 1 zeroes
    }
    long long int rsq(long long int b) { // returns RSQ(1, b)
        long long int summ = 0;
        for (; b; b -= (b & (-b)))
            summ += ft[b];
        return summ; 
    }
    long long int rsq(int a, int b) { // returns RSQ(a, b)
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(long long int k, long long int v) { // note: n = ft.size() - 1
        for (; k < ft.size(); k += (k & (-k)))
            ft[k] += v;
    }
};
int n, k, a, b;
int arr[1000003];
char c;
vector<int> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    scanf("%d %d\n", &n, &k);
    FenwickTree fenw(n);
    for (int i = 0; i < k; ++i) {
        scanf("%c", &c);
        if(c == 'C'){
            scanf("%d %d\n", &a, &b);
            ans.push_back(fenw.rsq(a, b));
        }
        else{
            scanf("%d\n", &a);
            if(arr[a]){
                arr[a] = 0;
                fenw.adjust(a, -1);
            }
            else{
                arr[a] = 1;
                fenw.adjust(a, 1);
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
