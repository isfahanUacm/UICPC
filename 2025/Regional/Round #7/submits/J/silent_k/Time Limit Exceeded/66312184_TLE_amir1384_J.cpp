#include <iostream>
#include <string>
#include <vector>

int main()
{
    using namespace std;

    int count = 0;
    cin >> count;

    int intervals = 0;
    cin >> intervals;

    vector<int> messages(count, 0);
    for (auto i = 0; i < count; ++i)
    {
        int value = 0;
        cin >> value;
        messages.push_back(value);
    }

    for (auto i = 0; i < intervals; ++i)
    {
        auto count = 0;
        int lower;
        cin >> lower;

        int upper;
        cin >> upper;

        for (int value : messages)
        {
            if (value >= lower && value <= upper)
            {
                ++count;
            }
        }

        cout << count << '\n';
    }
}