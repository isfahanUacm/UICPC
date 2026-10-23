#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;

    while (test--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int left = 0;
        int right = 0;
        int distinct = 0;
        int answer = n;

        while (right < n)
        {
            int currentDistinct = 1;

            for (int i = left + 1; i <= right; i++)
            {
                if (a[i] != a[i - 1])
                    currentDistinct++;
            }

            while (left <= right && a[right] - a[left] >= currentDistinct)
            {
                left++;
                currentDistinct = 1;

                for (int i = left + 1; i <= right; i++)
                {
                    if (a[i] != a[i - 1])
                        currentDistinct++;
                }
            }

            int deletions = n - (right - left + 1);

            if (deletions < answer)
                answer = deletions;

            right++;
        }

        cout << answer << '\n';
    }

}