#include <bits/stdc++.h>
using namespace std;
// Dp Memoization Approach  T.C=O(n)  S.C=O(n)+o(n)
int fibo1(int n, vector<int> &dp)
{
    if (n <= 1)
        return n + 1;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibo1(n - 1, dp) + fibo1(n - 2, dp);
}
// Tabulation Technique  T.C=O(n)  S.C=O(n)
int fibo3(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    if (n <= 1)
        return dp[n];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// Tabulation Technique with space optimization T.C=O(n)  S.C=O(1)
int fibo2(int n)
{
    int prev2 = 0;
    int prev1 = 1;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        int ans = prev1 + prev2;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev2;
}
int main()
{
    int n;
    cout << "Enter Value of N\n";
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout << fibo(n, dp);
    // cout << fibo2(n);
    cout << fibo3(n, dp);

    return 0;
}