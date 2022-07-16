#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> denoms;
    for (int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        denoms.push_back(ni);
    }
    /*
    Very similar to the 0-1 knapsack problem. Consider one denomination at a time and find the minimum number of ways to make each value up to the target.
    Minimum will either come from the above row for the same value, or 1 more than the value in the current row at the ~value - currentDenomination~ position
    */
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, INT32_MAX));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= target; j++) {
            int incl = INT32_MAX;
            int excl = dp[i - 1][j];
            if (j >= denoms[i - 1] && dp[i][j - denoms[i - 1]] != INT32_MAX) {
                incl = dp[i][j - denoms[i - 1]] + 1;
            }
            dp[i][j] = min(incl, excl);
        }
    }
    if (dp[n][target] == INT32_MAX) {
        cout << -1;
    }
    else {
        cout << dp[n][target];
    }
    return 0;
}