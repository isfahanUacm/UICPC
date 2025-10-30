
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long d, a, o, da, do_;
    cin >> d;
    cin >> a >> o;
    cin >> da >> do_;

  
    long double remaining_alcohol = (long double)a - (long double)d * (long double)da;
    long double remaining_other = (long double)o - (long double)d * (long double)do_;

    long double alcohol_percentage = 100.0L * remaining_alcohol / (remaining_alcohol + remaining_other);

    cout << fixed << setprecision(14) << alcohol_percentage << endl;

    return 0;
}

