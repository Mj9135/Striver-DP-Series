#include <bits\stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

// Memoization
int uniquePaths3(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (n < 0 || m < 0)
        return 0;
    if (grid[n][m] == 0)
        return 0;
    if (n == 0 && m == 0)
        return 1;

    if (dp[n][m] != -1)
        return dp[n][m];

    int up = 0, left = 0;
    if (n > 0)
    {
        up = uniquePaths3(n - 1, m, grid, dp) % mod;
    }
    if (m > 0)
    {
        left = uniquePaths3(n, m - 1, grid, dp) % mod;
    }

    dp[n][m] = (up + left) % mod;
    return dp[n][m];
}

// Tabulization
int uniquePaths2(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    dp[0][0] = 1;
    if (n <= 0 || m <= 0 || grid[0][0] == 0 || grid[n - 1][m - 1] == 0)
        return 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            else
            {
                int up = 0, left = 0;
                if (i > 0 && grid[i - 1][j] == 1)
                {
                    up = dp[i - 1][j] % mod;
                }
                if (j > 0 && grid[i][j - 1] == 1)
                {
                    left = dp[i][j - 1] % mod;
                }
                if (grid[i][j] == 1)
                {
                    dp[i][j] = (up + left) % mod;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }

    return dp[n - 1][m - 1];
}

// Tabulization with space optimization
int uniquePaths(int n, int m, vector<vector<int>> &grid)
{

    if (n <= 0 || m <= 0 || grid[0][0] == 0 || grid[n - 1][m - 1] == 0)
        return 0;

    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
            }
            else
            {
                int up = 0, left = 0;
                if (i > 0 && grid[i - 1][j] == 1)
                {
                    up = prev[j] % mod;
                }
                if (j > 0 && grid[i][j - 1] == 1)
                {
                    left = temp[j - 1] % mod;
                }
                if (grid[i][j] == 1)
                {
                    temp[j] = (up + left) % mod;
                }
                else
                {
                    temp[j] = 0;
                }
            }
        }
        prev = temp;
    }

    return prev[m - 1];
}
int main()
{
    vector<vector<int>> maze{
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    int n = maze.size();
    int m = maze[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << "Number of paths with obstacles: " << uniquePaths(n, m, maze) << endl;
    // cout << "Number of paths with obstacles: " << uniquePaths2(n, m, maze, dp) << endl;
    cout << "Number of paths with obstacles: " << uniquePaths3(n - 1, m - 1, maze, dp) << endl;
    return 0;
}