#include <iostream>
using namespace std;
int main() {
    int a,sum1,sum2,j,max=0;
    cin>> a;
    int arr[a],ans[a-1];
    for (int i = 0; i < a; ++i) {
        cin>>arr[i];
    }

    for (int i = 0; i < a-1; ++i) {
        sum1=sum2=0;
        for (j=0; j <= i; ++j) {
            sum1+=arr[j]*arr[j];
        }
        for (; j < a; ++j) {
            sum2+=arr[j];
        }
        ans[i] = sum2*sum1;
    }
    for (int i = 0; i < a-1; ++i) {
        if (ans[i] > max) {
            max = ans[i];
        }
    }
    cout<<max;
}
