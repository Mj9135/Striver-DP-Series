#include <bits/stdc++.h>
using namespace std;

// Recursion
bool subsetSumToK1(int ind, int k, vector<int> &arr)
{
    if (k == 0)
        return true;
    if (ind == 0)
        return arr[0] == k;
    bool notTaken = subsetSumToK1(ind - 1, k, arr);
    bool taken = false;
    if (arr[ind] <= k)
    {
        taken = subsetSumToK1(ind - 1, k - arr[ind], arr);
    }
    return taken || notTaken;
}

// Memoization
bool subsetSumToK2(int ind, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (ind == 0)
        return arr[0] == k;
    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }
    bool notTaken = subsetSumToK2(ind - 1, k, arr, dp);
    bool taken = false;
    if (arr[ind] <= k)
    {
        taken = subsetSumToK2(ind - 1, k - arr[ind], arr, dp);
    }
    return dp[ind][k] = taken || notTaken;
}

// Tabulization
bool subsetSumToK3(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= k)
    {
        dp[0][arr[0]] = true;
    }
    for (int ind = 1; ind <= n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = dp[ind - 1][target];
            bool taken = false;
            if (arr[ind] <= target)
            {
                taken = dp[ind - 1][target - arr[ind]];
            }

            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n][k];
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 10;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    if (subsetSumToK3(n - 1, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}