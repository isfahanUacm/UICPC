#include <bits/stdc++.h>
using namespace std;

// Virus

int main(){
    string x, y;
    cin >> x >> y;
    if(x == y)
        cout << 0 << endl;
    else{
        int x_size = x.size(), y_size = y.size();
        int xs = 0, ys = 0, xe = x_size - 1, ye = y_size - 1;
        while(xs < x_size && ys < y_size && x[xs] == y[ys])
            xs++, ys++;
        while(xe >= 0 && ye >= 0 && x[xe] == y[ye])   
            xe--, ye--;
        if(xs == x_size || xe == -1)
            cout << y_size - x_size << endl;
        else
            cout << max(0, ye - ys + 1) << endl;
    }
}