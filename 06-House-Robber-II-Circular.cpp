#include <bits/stdc++.h>
using namespace std;
int solve(int ind, vector<int> &nums)
{
    int prev2 = 0;
    int prev1 = nums[0];
    if (ind == 0)
        return prev1;
    for (int i = 1; i <= ind; i++)
    {
        int pick = nums[i] + prev2;

        int noPick = prev1;
        int curr = max(pick, noPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{

    vector<int> nums{1, 2, 3, 1};
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }
    cout << max(solve(n - 2, temp1), solve(n - 2, temp2));
    return 0;
}