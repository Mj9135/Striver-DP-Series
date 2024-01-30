#include <bits/stdc++.h>

using namespace std;

// Memoization function to find the minimum cost of frog jumping
int solve(int ind, vector<int> &height, vector<int> &dp)
{
    // Base case: when the frog is at the first stone
    if (ind == 0)
        return 0;

    // If the result for this index is already computed, return it
    if (dp[ind] != -1)
        return dp[ind];

    // Initialize cost for jumping one and two stones
    int jumpTwo = INT_MAX;
    int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);

    // Check if jumping two stones is valid (index > 1)
    if (ind > 1)
        jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);

    // Choose the minimum cost between jumping one and two stones
    return dp[ind] = min(jumpOne, jumpTwo);
}

int main()
{
    // Input heights of stones
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();

    // Initialize variables to keep track of the previous two results
    int prev = 0;
    int prev2 = 0;

    // Loop to calculate the minimum cost of frog jumping
    for (int i = 1; i < n; i++)
    {
        int jumpTwo = INT_MAX;
        int jumpOne = prev + abs(height[i] - height[i - 1]);

        // Check if jumping two stones is valid (index > 1)
        if (i > 1)
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);

        // Choose the minimum cost between jumping one and two stones
        int cur_i = min(jumpOne, jumpTwo);

        // Update previous two results for the next iteration
        prev2 = prev;
        prev = cur_i;
    }

    // Output the minimum cost of frog jumping
    cout << prev;
    return 0;
}
