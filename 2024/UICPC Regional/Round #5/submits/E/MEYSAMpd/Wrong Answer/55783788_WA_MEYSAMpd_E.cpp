#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define d double

void merge(ull arr[], ull low, ull mid, ull high) {
    ull n1 = mid - low + 1;  // size of left side array.
    ull n2 = high - mid;  // size of right side.
    ull left[n1], right[n2];

    for (ull i=0; i<n1; i++)
        left[i] = arr[low + i];

    for (ull i=0; i<n2; i++)
        right[i] = arr[mid+i+1];

    ull i=0, j=0, k=low;

    while (((i<n1) && (j<n2)))
    {
        if (left[i] < right[j])
            arr[k] = left[i++];
        else
            arr[k] = right[j++];
        k++;
    }

    while (i<n1)
        arr[k++] = left[i++];

    while (j<n2)
        arr[k++] = right[j++];

}

void mergeSort(ull arr[], ull low, ull high) {
        if (low >= high)
            return;

        ull mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
}

int main() {


    ull n, m,l;
    ull poses[100005], bulbs[100005];
    cin >> n >> m >> l;

    for (ull i=0; i<n; i++)
        cin >> poses[i];
    poses[n] = l;

    mergeSort(poses, 0, n);

//    for (ull i =0 ; i<n+1 ; i++)
//        cout << poses[i] << " ";

    ull tmp =0;
    ull max1 =0;
    for (ull i =0 ; i<n+1 ; i++) {
        if ((poses[i]-tmp) > max1)
            max1 = poses[i]-tmp;
        tmp = poses[i];
    }

    for (ull i=0; i<m; i++) {
        cin >> bulbs[i];
    }
    mergeSort(bulbs, 0, m-1);

    ll ans = -1;
    for (ull i=0; i<m; i++) {
        if (bulbs[i] >= max1) {
            ans = bulbs[i];
            break;
        }

    }

    cout << ans;

//    ll ans = l;
//    for (ull i =0 ; i<m ; i++) {
//        cin >> tmp;
//        if ((tmp >= max1) && (tmp <= ans)) {
//            ans = tmp;
//        }
//    }

//    if (ans != l)
//        cout << ans;
//    else cout << -1;

    return 0;
}