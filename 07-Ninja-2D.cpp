//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// Recursion
int solve2(int days, int last, vector<vector<int>> &points)
{
    if (days == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(points[0][task], maxi);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[days][task] + solve2(days - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}
// Memoization
int solve(int days, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (days == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(points[0][task], maxi);
            }
        }
        return maxi;
    }
    if (dp[days][last] != -1)
        return dp[days][last];
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[days][task] + solve(days - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[days][last] = maxi;
}

// Tabulization without space optimization
int tab(vector<vector<int>> &points, int day)
{
    vector<vector<int>> dp(day + 1, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for (int i = 1; i <= day; i++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[i][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[i][task] + dp[i - 1][task];
                    dp[i][last] = max(dp[i][last], point);
                }
            }
        }
    }

    return dp[day][3];
}

int main()
{
    vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    int n = points.size();
    cout << tab(points, n - 1);
    return 0;
}
