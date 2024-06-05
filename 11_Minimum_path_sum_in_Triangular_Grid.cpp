#include <bits\stdc++.h>
using namespace std;
int minimumPathSum(vector<vector<int>> triangle, int i, int j, int n)
{
    if (i == n)
    {
        return triangle[i][j];
    }
    int down = triangle[i][j] + minimumPathSum(triangle, i + 1, j, n);
    int diagonal = triangle[i][j] + minimumPathSum(triangle, i + 1, j + 1, n);
    return min(down, diagonal);
}

// Memoization Approach
int minimumPathSum2(vector<vector<int>> &triangle, int i, int j, int n, vector<vector<int>> &dp)
{
    if (i == n)
        return dp[i][j] = triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + minimumPathSum2(triangle, i + 1, j, n, dp);
    int diagonal = triangle[i][j] + minimumPathSum2(triangle, i + 1, j + 1, n, dp);
    return dp[i][j] = min(down, diagonal);
}

// Tabulization without space optimization
int minimumPathSum3(vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        dp[n][i] = triangle[n][i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

// Tabulization with space optimization
int minimumPathSum4(vector<vector<int>> &triangle, int n)
{
    vector<int> dp(n);
    for (int i = 0; i <= n; i++)
    {
        dp[i] = triangle[n][i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j <= i; j++)
        {
            int down = triangle[i][j] + dp[j];
            int diagonal = triangle[i][j] + dp[j + 1];
            temp[j] = min(down, diagonal);
        }
        dp = temp;
    }
    return dp[0];
}
int main()
{

    vector<vector<int>> triangle{{2},
                                 {3, 4},
                                 {6, 5, 7},
                                 {4, 1, 8, 3}};
    int n = triangle.size();
    vector<vector<int>> dp(n, (vector<int>(n)));
    cout << "Minimum Path Sum Of Triangle is:" << minimumPathSum4(triangle, n - 1);

    return 0;
}