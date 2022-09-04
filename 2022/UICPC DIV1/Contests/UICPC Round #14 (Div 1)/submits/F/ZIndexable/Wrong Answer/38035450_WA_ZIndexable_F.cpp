#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> letters(26);

    string str1, str2;
    cin >> str1 >>str2;

    int size =str1.size();

    long ans = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = i +1; j < size; ++j) {
            bool suc = true;
            for (int k = 0; k < i; ++k) {
                if (str1[k] != str2[k]){
                    suc = false;
                    break;
                }
            }
            if (suc == false)
                continue;

            int len = j - i;

            for (int k = 0; k <= (len / 2) + 1; ++k) {
                if (str1[i + k] != str2[j - k]){
                    suc = false;
                    break;
                }
            }

            if (suc == false)
                continue;

            if(j + 1 < size)
                for (int k = j + 1; k < size; ++k) {
                    if (str1[k] != str2[k]){
                        suc = false;
                        break;
                    }
                }

            if(suc)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
