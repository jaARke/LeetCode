#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int runCase(int idx, int m, int k, vector<vector<vector<int>>>& dp) {
    // Bases cases:
    if (k == 1) {
        return m*(m + 1) / 2 - idx*(idx + 1) / 2;
    }
    if (idx >= m) {
        return 0;
    }
    
    if (dp[k][idx][m] == INT32_MIN) {   // This value has not been considered before
        int currMin = INT32_MAX;
        for (int j = idx + 1; j <= m; j++) {
            int tempMax = j + max(runCase(j, m, k, dp), runCase(idx, j - 1, k - 1, dp));
            currMin = min(currMin, tempMax);
        }
        dp[k][idx][m] = currMin;
    }
    return dp[k][idx][m];
}


int main() {
    int n;
    cin >> n;

    vector<vector<vector<int>>> dp(11, vector<vector<int>>(101, vector<int>(101, INT32_MIN)));  // Same dp array for all test cases
    for (int i = 0; i < n; i++) {
        int k, m;
        cin >> k >> m;
        cout << runCase(0, m, k, dp) << endl;
    }
    return 0;
}