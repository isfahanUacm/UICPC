#include <bits/stdc++.h>
using namespace std;

// Datum

int month_days[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string week_days[7]{"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};

int main(){
    int d, m;
    cin >> d >> m;
    for(int i = 0; i < m; i++)
        d += month_days[i];
    cout << week_days[d % 7] << '\n';
}