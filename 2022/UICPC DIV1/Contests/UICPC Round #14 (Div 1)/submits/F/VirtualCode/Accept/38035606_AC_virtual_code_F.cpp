#include <iostream>
#include <vector>
using namespace std;
string q1, q2,x1, x2;
vector<int> diff;
int ways = 0;
void get(){
    cin >> q1 >> q2;
}
void d1(){
    for(auto i : q1) {
        x1.push_back(i);
        x1.push_back('.');
    }
    x1.pop_back();
}
void d2(){
    for(auto i : q2) {
        x2.push_back(i);
        x2.push_back('.');
    }
    x2.pop_back();
}
void d3(){
    int i = 0;
    while(i < x1.size()) {
        if(x1[i] != x2[i]) {
            diff.push_back(i);
        }
        i++;
    }
}
void dis(){
    cout << ways << endl;
}




int main() {
    get();
    d1();
    d2();
    d3();
    if(diff.size() % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    int center = (diff.front() + diff.back()) / 2;
    int l = center;
    int r = center;
    while(true) {
        if(x1[l] == x2[r] && x1[r] == x2[l]) {
            l--;
            r++;
        }
        else {
            break;
        }
        if(l < 0 || r >= x1.size()) {
            break;
        }
    }
    r--;
    l++;
    if(l > diff.front() || r < diff.back()) {
        cout << 0 << endl;
        return 0;
    }
    int i = l;
    while( i <= diff.front()) {
        if(x1[i] != '.'){ ways++;}
        i++;
    }
    dis();
}