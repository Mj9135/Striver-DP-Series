#include <bits/stdc++.h>
using namespace std;
// Memoization
int solve1(int ind, vector<int> &arr, vector<int> &dp)
{
    if (ind == 0)
        return dp[ind] = arr[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int pick = arr[ind] + solve1(ind - 2, arr, dp);
    int noPick = solve1(ind - 1, arr, dp);
    return dp[ind] = max(pick, noPick);
}

// Tabulization without space optimization
int solve2(int ind, vector<int> &arr, vector<int> &dp)
{
    dp[0] = arr[0];
    if (ind == 0)
        return dp[ind];
    for (int i = 1; i <= ind; i++)
    {
        int pick = arr[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int noPick = dp[i - 1];
        dp[i] = max(pick, noPick);
    }
    return dp[ind];
}

// Tabulization with space optimization
int solve3(int ind, vector<int> &arr)
{
    int prev2 = 0;
    int prev1 = arr[0];
    if (ind == 0)
        return prev1;
    for (int i = 1; i <= ind; i++)
    {
        int pick = arr[i] + prev2;

        int noPick = prev1;
        int curr = max(pick, noPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{

    vector<int> arr{5, 5, 10, 100, 10, 5};
    int n = arr.size();
    vector<int> dp(n, -1);
    cout << solve2(n - 1, arr, dp);
    return 0;
}