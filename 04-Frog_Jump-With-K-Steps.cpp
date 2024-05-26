#include <bits/stdc++.h>
using namespace std;
// Tabulation
int solve1(int ind, vector<int> &height, int k, vector<int> &dp)
{
    dp[0] = 0;
    if (ind <= 0)
        return 0;

    for (int i = 1; i <= ind; i++)
    {
        int steps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if ((i - j) >= 0)
            {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                steps = min(steps, jump);
            }
        }
        dp[i] = steps;
    }
    return dp[ind];
}

// Memoization
int solve2(int ind, vector<int> &height, int k, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int steps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if ((ind - j) >= 0)
        {
            int jump = solve2(ind - j, height, k, dp) + abs(height[ind] - height[ind - j]);
            steps = min(steps, jump);
        }
    }
    return dp[ind] = steps;
}
int main()
{

    vector<int> height{10, 30, 40, 50, 20};
    int n = height.size();
    vector<int> dp(n, -1);
    int k = 3;
    int ans = solve2(n - 1, height, k, dp);
    cout << ans;
    return 0;
}