#include <bits/stdc++.h>
#include <string>
#include <cstring>
using namespace std;
int main() {

    long int n;
    int sum = 0;

    cin >> n;

    if (n < 10){
        cout << n+1;
        return 0;
    }
    else {
        string num = to_string(n);

        sum += 10 * (num.length()-1);

        for(int i = num[0] -'0';i >0;i--){
            string x = string();
            for(int j = 0;j<num.length();j++){
                x += i + '0';
            }

            if(n >= stoi(x))
                sum++;
        }

    }

    cout << sum;

    return 0;
}
