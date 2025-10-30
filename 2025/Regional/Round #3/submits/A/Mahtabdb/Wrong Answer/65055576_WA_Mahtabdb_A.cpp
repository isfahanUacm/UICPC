#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    long long d, a, o, da, do_;
    cin >> d;
    cin >> a >> o;
    cin >> da >> do_;


    long long remaining_alcohol = a - d * da;
    long long remaining_other = o - d * do_;

    double alcohol_percentage = 100.0 * remaining_alcohol / (remaining_alcohol + remaining_other);

  
    cout << fixed << setprecision(12) << alcohol_percentage << endl;

    return 0;
}
