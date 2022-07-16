#include <bits/stdc++.h>

using namespace std;


/*
- seems like the edit distance problem
- we just have to build out the solution at the end
- we can backtrack the solution to print the choices we made as discussed in class
*/

void print(int i, int j, string &s, string &t, vector<vector<int>> &dp) {

    if (i == 0 && j == 0) { return; }

    if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
        print(i - 1, j, s, t, dp);
        cout << "DELETE " << j + 1 << "\n";
    }

    else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
        print(i, j - 1, s, t, dp);
        cout << "INSERT " << j << " " << t[j - 1] << "\n";
    }

    else {
        print(i - 1, j - 1, s, t, dp);

        if (s[i - 1] != t[j - 1]) {
            cout << "REPLACE " << j << " " << t[j - 1] << "\n";
        }
    }
}
int main() {

    string s, t;
    cin >> s;
    cin >> t;

    int n = s.size();
    int m = t.size();

    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));


    // empty prefix, we can only insert characters
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }

    // empty suffix, we can only remove characters
    for (int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            /* characters match, so we dont have to do anything */
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }

            /* choose operation that costs the least */
            else {
                dp[i][j] = min({dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
            }
        }
    }

    cout << dp[n][m] << "\n";
    print(n, m, s, t, dp);
    return 0;
}