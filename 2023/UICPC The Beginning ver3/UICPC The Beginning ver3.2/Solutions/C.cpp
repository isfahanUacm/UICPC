#include <bits/stdc++.h>
using namespace std;

int largestSumAfterKNegations(vector<int> &nums, int k)
{
    int sum = 0, i = 0, length = nums.size();
    sort(nums.begin(), nums.end());
    while (nums[i] < 0 && i < length)
    {
        if (k <= 0)
            break;
        nums[i] *= -1;
        i++;
        k--;
    }
    sort(nums.begin(), nums.end());
    if (k > 0 && nums[0] != 0)
        if (k % 2)
            nums[0] *= -1;
    for (auto x : nums)
    {
        sum += x;
    }
    return sum;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << largestSumAfterKNegations(nums, k) << endl;
    return 0;
}
