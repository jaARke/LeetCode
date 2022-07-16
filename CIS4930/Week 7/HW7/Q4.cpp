#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int roundCost(int cost) {   // Round to nearest multiple of 10
    if (cost % 10 >= 5) {
        cost += 10;
    }
    cost -= cost % 10;
    return cost;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<vector<int>> dp(n + 1, vector<int>(d + 1, 0));
    vector<int> p;
    for (int i = 1; i <= n; i++) {  // Collect input and fill each 0th entry of the dp with the running sum of costs
        int pi;
        cin >> pi;
        dp[i][0] = dp[i - 1][0] + pi;
        p.push_back(pi);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d; j++) {
            int prevDiv = roundCost(dp[i - 1][j - 1] + p[i - 1]);   // Only need to check the previous division because no reordering is allowed
            dp[i][j] = min(dp[i - 1][j] + p[i - 1], prevDiv);
        }
    }
    int result = INT32_MAX;
    for (int i = 0; i < dp[n].size(); i++) {
        int dpni = roundCost(dp[n][i]);
        result = min(result, dpni);
    }
    cout << result << endl;
    return 0;
}