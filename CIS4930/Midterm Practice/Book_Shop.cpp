#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> prices;
    vector<int> pages;
    for (int i = 0; i < n; i++) {
        int pi;
        cin >> pi;
        prices.push_back(pi);
    }
    for (int i = 0; i < n; i++) {
        int pi;
        cin >> pi;
        pages.push_back(pi);
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            int excl = dp[i - 1][j];
            int incl = INT32_MIN;
            if (j >= prices[i - 1]) {
                incl = pages[i - 1] + dp[i - 1][j - prices[i - 1]];
            }
            dp[i][j] = max(incl, excl);
        }
    }
    cout << dp[n][x];
    return 0;
}
    