#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>

using namespace std;
using ll = long long;


int main(){
    int n, p;
    cin >> n >> p;

    vector<vector<int>> counter(n + 1, vector<int>(p + 1));
    vector<vector<string>> solv(n + 1, vector<string>(p + 1));
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= p; j ++){
            cin >> solv[i][j];
            cin >> counter[i][j];
        }
    
    for (int j = 1; j <= p; j++){
        for (int k = 1; k <= 3; k++){
            if (k == 1){
                int count = 0;
                for (int i = 1; i <= n; i++){
                    if (solv[i][j] == "+")
                        count++;
                }
                cout << count << " ";
            }
            else if (k == 2){
                int count = 0;
                for (int i = 1; i <= n; i++){
                    if (counter[i][j])
                        count++;
                    else{
                        if (solv[i][j] == "+")
                            count++;
                    }
                }
                cout << count << " ";
            }
            else{
                int count = 0;
                for (int i = 1; i <= n; i++){
                    count += counter[i][j];
                }
                cout << count << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}