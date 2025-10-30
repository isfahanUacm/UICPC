#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long d, a, o, da, do_;
    cin >> d >> a >> o >> da >> do_;

    long double remaining_alcohol = (long double)a - (long double)d * (long double)da;
    long double remaining_other = (long double)o - (long double)d * (long double)do_;

    long double alcohol_percentage;


    if(remaining_alcohol <= 0.0L) {
        alcohol_percentage = 0.0L;
    } else if(remaining_other <= 0.0L) {
        alcohol_percentage = 100.0L;
    } else {
        alcohol_percentage = 100.0L * remaining_alcohol / (remaining_alcohol + remaining_other);
    }

    cout << fixed << setprecision(12) << alcohol_percentage << endl;

    return 0;
}
