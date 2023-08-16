#include<bits/stdc++.h>
using namespace std;
using ll =long long;

ll merge_count(vector<int> &arr, int l, int m1, int m2, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m1 + 1);
    vector<int> middle(arr.begin() + m1 + 1, arr.begin() + m2 + 1);
    vector<int> right(arr.begin() + m2 + 1, arr.begin() + r + 1);
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);
    middle.push_back(INT_MAX);

    ll inv = 0;
    int i = 0, j = 0, w=0, k = l;

    while (left[i] != INT_MAX || middle[j] != INT_MAX || right[w] != INT_MAX) {
        if (left[i] <= middle[j] && left[i] <= right[w]) {
            arr[k++] = left[i++];
        } else if (middle[j] <= right[w]) {
            inv += max((int)left.size()- i - 1, 0) * w;
            arr[k++] = middle[j++];
        } else {
            arr[k++] = right[w++];
        }
    }

    return inv;
}

ll mergesort(vector<int> &arr, int l, int r) {
    ll inv = 0;
    if (l < r) {
        int m1 = l + (r - l) / 3;
        int m2 = l + 2 * (r - l) / 3;
        // cout<<l<<' '<<m1<<' '<<m2<<' '<<r<<endl;
        inv += mergesort(arr, l, m1);
        inv += mergesort(arr, m1 + 1, m2);
        inv += mergesort(arr, m2 + 1, r);
        inv += merge_count(arr, l, m1, m2, r);
    }
    return inv;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cout << mergesort(arr, 0, n-1) << endl;

    return 0;
}