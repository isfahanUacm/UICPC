#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int department, building;
    cin >> department >> building;

    // Input department max student requirements
    int max[department];
    for (int i = 0; i < department; i++) {
        cin >> max[i];
    }

    // Input building capacities and prices
    int capacity[building];
    int prices[building];
    for (int i = 0; i < building; i++) {
        cin >> capacity[i];
    }
    for (int i = 0; i < building; i++) {
        cin >> prices[i];
    }

    // Calculate total max capacity and max students
    int totalCapacity = 0, totalStudents = 0;
    for (int i = 0; i < building; i++) {
        totalCapacity += capacity[i];
    }
    for (int i = 0; i < department; i++) {
        totalStudents += max[i];
    }

    // Check if it's possible to allocate buildings
    if (totalCapacity < totalStudents) {
        cout << "impossible" << endl;
        return 0;
    }

    // Result array to store assigned building for each department
    int result[department];
    fill(result, result + department, -1);

    // Assign buildings to departments
    for (int i = 0; i < department; i++) {
        int maxStudents = max[i];  // Number of students for this department
        int bestBuilding = -1;
        int bestPrice = INT_MAX;

        // Find the best building with enough capacity and lowest price
        for (int j = 0; j < building; j++) {
            if (capacity[j] >= maxStudents && prices[j] < bestPrice) {
                bestBuilding = j;
                bestPrice = prices[j];
            }
        }

        if (bestBuilding != -1) {
            // Assign the best building to the department
            result[i] = bestBuilding + 1;
            capacity[bestBuilding] -= maxStudents;  // Reduce the capacity of that building
        }
    }

    // Output the results
    for (int i = 0; i < department; i++) {
        if (result[i] != -1) {
            cout << result[i] << " ";
        } else {
            cout << "impossible ";
        }
    }
    cout << endl;

    return 0;
}
