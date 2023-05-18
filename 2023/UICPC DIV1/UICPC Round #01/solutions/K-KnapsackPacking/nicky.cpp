#include <iostream>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    int n;
    multiset<int> items;
    multiset<int> answer;
    cin >> n;
    int p = pow(2, n);

    for (int i = 0; i < p; i++) {
        int item;
        cin >> item;
        items.insert(item);
    }

    while (items.size() > 1) {
        auto s1ptr = ++items.begin();
        auto s1 = *s1ptr;
        answer.insert(s1);
        multiset<int> newItems;
        while (!items.empty()) {
            auto s2ptr = items.begin();
            auto s2 = (*s2ptr);
            auto s1s2 = s1 + s2;
            items.erase(s2ptr);
            auto s1s2ptr = items.find(s1s2);
            if (s1s2ptr == items.end()) {
                cout << "impossible" << endl;
                return 0;
            }
            items.erase(s1s2ptr);
            newItems.insert(s2);
        }
        items = newItems;
    }

    for (auto a : answer) {
        cout << a << endl;
    }

    return 0;
}
