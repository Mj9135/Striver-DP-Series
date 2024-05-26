#include <bits/stdc++.h>

using namespace std;
// Recursion Way to solve
int solve2(int ind, vector<int> &height)
{
    if (ind == 0)
        return 0;
    int left = solve2(ind - 1, height) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        int right = solve2(ind - 2, height) + abs(height[ind] - height[ind - 2]);
    }
    int ans = min(left, right);
    return ans;
}

// Memoization Technique
int solve1(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int left = solve1(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = solve1(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
    }

    dp[ind] = min(left, right);
    return dp[ind];
}

// Tabulization without space optimization
int solve2(int ind, vector<int> &height, vector<int> &dp)
{
    dp[0] = 0;
    if (ind <= 0)
        return dp[ind];

    for (int i = 1; i <= ind; i++)
    {
        int left = dp[i - 1] + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(height[i] - height[i - 2]);
        }

        dp[i] = min(left, right);
    }
    return dp[ind];
}

// Tabulization  with space optimization
int solve3(int ind, vector<int> &height)
{
    int prev = 0;
    int prev2 = 0;
    if (ind <= 0)
        return ind;
    for (int i = 1; i <= ind; i++)
    {
        int left = prev + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = prev2 + abs(height[i] - height[i - 2]);
        }
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main()
{

    vector<int> height{10, 20, 30, 10};
    int n = height.size();
    vector<int> dp(n, -1);
    int ans = solve3(n - 1, height);
    cout << ans;
    return 0;
}
