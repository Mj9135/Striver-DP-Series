#include <bits/stdc++.h>
using namespace std;

// Recursion
int getMaxPathSum(vector<vector<int>> &matrix, int i, int j, int n)
{
    if (i == 0)
    {
        return matrix[i][j];
    }
    int one = INT_MAX, two = INT_MAX, three = INT_MAX;
    if (j < n)
    {
        one = matrix[i][j] + getMaxPathSum(matrix, i - 1, j + 1, n);
    }

    two = matrix[i][j] + getMaxPathSum(matrix, i - 1, j, n);
    if (j > 0)
    {
        three = matrix[i][j] + getMaxPathSum(matrix, i - 1, j - 1, n);
    }
    return min(one, min(two, three));
}

// Memoziation
int getMaxPathSum2(vector<vector<int>> &matrix, int i, int j, int n, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return matrix[i][j];
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int one = INT_MAX, two = INT_MAX, three = INT_MAX;
    if (j < n)
    {
        one = matrix[i][j] + getMaxPathSum2(matrix, i - 1, j + 1, n, dp);
    }

    two = matrix[i][j] + getMaxPathSum2(matrix, i - 1, j, n, dp);
    if (j > 0)
    {
        three = matrix[i][j] + getMaxPathSum2(matrix, i - 1, j - 1, n, dp);
    }
    return dp[i][j] = min(one, min(two, three));
}

// Tabulization
int getMaxPathSum3(vector<vector<int>> &matrix, int i, int j, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = matrix[0][i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int one = INT_MAX, two = INT_MAX, three = INT_MAX;
            if (j < n)
            {
                one = matrix[i][j] + dp[i - 1][j + 1];
            }

            two = matrix[i][j] + dp[i - 1][j];
            if (j > 0)
            {
                three = matrix[i][j] + dp[i - 1][j - 1];
            }
            dp[i][j] = min(one, min(two, three));
        }
    }
    return dp[n][j];
}

// Space optimization

int main()
{

    vector<vector<int>>
        matrix{
            {2, 1, 3},
            {6, 5, 4},
            {7, 8, 9},

        };
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, (vector<int>(n, -1)));

    int mini = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        int temp = getMaxPathSum3(matrix, 0, i, n - 1, dp);
        mini = min(temp, mini);
    }

    cout << "Min Falling path sum:" << mini;
    return 0;
}