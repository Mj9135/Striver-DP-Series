
#include <bits/stdc++.h>
using namespace std;
// Memoization
int countWaysUtil1(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = countWaysUtil1(i - 1, j, dp);
    int left = countWaysUtil1(i, j - 1, dp);
    return dp[i][j] = up + left;
}
// Tabulization approach
int countWaysUtil2(int m, int n, vector<vector<int>> &dp)
{
    dp[0][0] = 1;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            int up = 0, left = 0;
            if (i > 0)
            {
                up = dp[i - 1][j];
            }
            if (j > 0)
            {
                left = dp[i][j - 1];
            }
            dp[i][j] = up + left;
        }
    }
    return dp[m][n];
}

// Tabulization with space optimization
int countWaysUtil3(int m, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if (i > 0)
            {
                up = prev[j];
            }
            if (j > 0)
            {
                left = temp[j - 1];
            }
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n - 1];
}
int main()
{
    int m = 3;
    int n = 2;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = countWaysUtil3(m, n);
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << ans << endl;
    return 0;
}
