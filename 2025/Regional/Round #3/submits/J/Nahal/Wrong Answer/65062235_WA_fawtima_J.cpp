#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    cin.ignore();

    vector<string> names;
    vector<double> nums;
    vector<string> result;
    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        string name;
        double num;
        ss >> name;


        if (ss >> num) {
            names.push_back(name);
            nums.push_back(num);
        } else {
            result.push_back(name);
            nums.push_back(0);
        }
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    double temp = 0;
    vector<double> mins;
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] == 0) {
            mins.push_back(temp);
            nums[i] = temp;
        } else {
            temp = nums[i];
        }
    }
    if (sum == 0) {
        mins[mins.size()-1] = 100 / result.size();
    }

    vector<double> maxs;
    if (sum != 0) {
        maxs.push_back(100 - sum);
    }


    double sum2 = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum2 += nums[i];
    }
    double flag = 100 - sum2;
    int j = 0;
    for (j = 1; j < mins.size(); ++j) {
        maxs.push_back(flag / double(j));
    }
    if (sum2 == 0) {
        maxs.push_back(flag / double(j));
    }

    reverse(mins.begin(), mins.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " " << mins[i] << " " << maxs[i] << endl;
    }

    return 0;
}
