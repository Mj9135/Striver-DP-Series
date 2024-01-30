#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    int prev2 = 1;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    cout << prev << " ways to reach on the top of stairs";
    return 0;
}