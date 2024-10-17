#include <iostream>
#include <algorithm>


int getMaxim(int *arr, int n);
using namespace std;

int main() {
    int building, department;
    cin >> department >> building;
    int max[department];
    for (int i = 0; i < department; i++) {
        cin >> max[i];
    }
    int index;
    int capacity[building];
    int prices[building];
    for (int i = 0; i < building; i++) {
        cin >> capacity[i];
    }
    for (int i = 0; i < building; i++) {
        cin >> prices[i];
    }
    int maxcapaciry = 0;
    int maxstudents = 0;
    for ( int i = 0 ; i < building ; i++){
        maxcapaciry += capacity[i];
    }
    for ( int i = 0 ; i < department ; i++){
        maxstudents += max[i];
    }
    if ( maxcapaciry < maxstudents){
        cout << "impossible";
        return 0;
    }
    int result[department];
    for (int i = 0; i < department; i++) {
        int* maxS = max_element(max, max+building);
        int maxIndex = distance(max, maxS);
        int price = INT_MAX;

        for (int j = 0; j < building; j++) {
            if (capacity[j] >= *maxS && prices[j] <= price){
                index = j;
                price = prices[j];
            }
        }
        capacity[index] = -1;
        result[maxIndex] = index+1;
        max[maxIndex] = -1;
    }
    for (int i = 0 ; i < department ; i++){
        cout << result[i] << " ";
    }
}