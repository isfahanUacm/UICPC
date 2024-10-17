#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    double sum = 0.0;
    double x;

    for(int i = 0;i<n;i++){
        cin >> x;

        if(x == 0){
            sum += 2.0;
        }
        else {
            sum += 1.0 / x;
        }
    }
    printf("%.8f",sum);
    return 0;
}