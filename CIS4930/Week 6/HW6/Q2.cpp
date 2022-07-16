#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int totalDel = 0;
    vector<vector<int>> dp(n + 1, vector<int>(2016 + 1, INT32_MAX));
    for (int i = 1; i <= n; i++) {
        int di, ci, fi, ui;
        cin >> di >> ci >> fi >> ui;
        totalDel += di;
        int cost = (((fi - ci) + ui) / 2) + 1;
        if ((fi - ci) + ui < 0) {   // State is already won
            cost = 0;
        }
        else if (cost > ui) {   // State is already lost
            cost = INT32_MAX;
        }
        for (int j = 1; j <= 2016; j++) {
            int excl = dp[i - 1][j];
            int incl = INT32_MAX;
            if (j <= di) {
                incl = cost;
            }
            else if (dp[i - 1][j - di] != INT32_MAX && cost != INT32_MAX) {
                incl = cost + dp[i - 1][j - di];
            }
            dp[i][j] = min(incl, excl);
        }
    }
    totalDel /= 2;
    totalDel++;
    if (dp[n][totalDel] == INT32_MAX) {
        cout << "impossible" << endl;
    }
    else {
        cout << dp[n][totalDel] << endl;
    }
    return 0;
}