#include <bits\stdc++.h>
using namespace std;
// Recursion Technique
int solve(vector<vector<int>> &grid, int m, int n)
{
    if (m == 0 && n == 0)
        return grid[m][n];
    if (m < 0 || n < 0)
        return 1e7;
    int up = grid[m][n] + solve(grid, m - 1, n);
    int left = grid[m][n] + solve(grid, m, n - 1);
    return min(left, up);
}

// Memoization Technique
int solve2(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return grid[m][n];
    int up = INT_MAX, left = INT_MAX;
    if (m > 0)
    {
        up = grid[m][n] + solve2(m - 1, n, grid, dp);
    }
    if (n > 0)
    {
        left = grid[m][n] + solve2(m, n - 1, grid, dp);
    }
    return dp[m][n] = min(up, left);
}

// Tabulization without space optimzation
int solve3(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
                continue;
            }
            int up = INT_MAX, left = INT_MAX;
            if (i > 0)
            {
                up = grid[i][j] + dp[i - 1][j];
            }
            if (j > 0)
            {
                left = grid[i][j] + dp[i][j - 1];
            }
            dp[i][j] = min(up, left);
        }
    }
    return dp[m][n];
}
// Space optimized
int solve4(int m, int n, vector<vector<int>> &grid)
{
    vector<int> prev(n + 1, 0);
    for (int i = 0; i <= m; i++)
    {
        vector<int> temp(n + 1, 0);
        for (int j = 0; j <= n; j++)
        {

            if (i == 0 && j == 0)
            {
                temp[j] = grid[i][j];
                continue;
            }
            int up = INT_MAX, left = INT_MAX;
            if (i > 0)
            {
                up = grid[i][j] + prev[j];
            }
            if (j > 0)
            {
                left = grid[i][j] + temp[j - 1];
            }
            temp[j] = min(up, left);
        }
        prev = temp;
    }
    return prev[n];
}
int main()
{
    vector<vector<int>> grid{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "Minimum path sum is : " << solve4(n - 1, m - 1, grid) << endl;
    return 0;
}
