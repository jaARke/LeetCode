#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //cout << m << " " << n << endl;
    for (int i = 0; i <= m; ++i)
        dp[n][i] = i;
    vector<int> foods(n);
    for (int i = 0; i < n; ++i)
        cin >> foods[i];
    for (int i = n - 1; i > -1; --i)
        for (int sum = m; sum > -1; --sum)
        {
            if (sum + foods[i] <= m)
                dp[i][sum] = max(dp[i + 1][sum + foods[i]], dp[i + 1][sum]);
            else
                dp[i][sum] = dp[i + 1][sum];
        }
    cout << m - dp[0][0];
    return 0;
}