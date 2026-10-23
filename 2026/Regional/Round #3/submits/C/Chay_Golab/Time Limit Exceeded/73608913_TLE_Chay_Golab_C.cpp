#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        int size;
        cin >> size;

        vector<int> arr(size);

        for (int i = 0; i < size; i++)
            cin >> arr[i];

        sort(arr.begin(), arr.end());

        int distinct = 0;
        for (int i = 0; i < size; i++)
        {
            if (i == 0 || arr[i] != arr[i - 1])
                distinct++;
        }

        int answer = size;

        for (int left = 0; left < size; left++)
        {
            for (int right = left; right < size; right++)
            {
                int uniqueCount = 1;

                for (int k = left + 1; k <= right; k++)
                {
                    if (arr[k] != arr[k - 1])
                        uniqueCount++;
                }

                if (arr[right] - arr[left] < uniqueCount)
                {
                    int remaining = right - left + 1;
                    if (size - remaining < answer)
                        answer = size - remaining;
                }
            }
        }

        cout << answer << '\n';
    }

}