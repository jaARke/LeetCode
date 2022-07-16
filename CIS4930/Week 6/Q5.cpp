#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));

        // Base cases
        dp[0][0] = true;
        for (int i = 1; i <= p.length(); i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 1];
            }
        }
        // Knapsack-like implementation of dp array
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                switch (p[j - 1]) {
                    case '*':
                        if (dp[i - 1][j] || dp[i][j - 1]) {
                            dp[i][j] = true;
                        }
                        break;
                    
                    case '?':
                        dp[i][j] = dp[i - 1][j - 1];
                        break;

                    default:
                        if (p[j - 1] == s[i - 1]) {
                            dp[i][j] = dp[i - 1][j - 1];
                        }
                        break;
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};

// !!!USED FOR TESTING:
int main() {
    Solution s;
    string st = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    string p = "a*******b";
    if (s.isMatch(st, p)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}
