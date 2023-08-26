#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;

typedef pair<int,int> pii;
typedef vector<pair<int, int>> vii;

typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;

int point(string m) {


}

int main() {
    int rep;
    cin >>rep;
    for (int i = 0; i < rep; ++i) {
        int a;
        cin >>a;
        vi p(a);
        vi r(a);
        for (int j = 0; j < a; ++j) {
            string tmp;
            cin >>tmp;
            int point=0;
            int rem =0;
            for(auto s : tmp) {
                if (s == '1') {
                    point += 2;
                } else if(s == 'd'){
                    point += 1;
                } else if(s=='.') {
                    rem+=1;
                }
            }
            p[j]  =point;
            r[j] = rem;
        }

        int max = *max_element(p.begin(), p.end());

        for (int j = 0; j < a; ++j) {
            if ((p[j] + (r[j]*2)) >= max){
                cout << j+1 <<" ";
            }
        }
        cout <<endl;
    }
    return 0;
}
