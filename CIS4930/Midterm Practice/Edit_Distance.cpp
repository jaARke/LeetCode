#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    /*
    Consider each char one at a time in each string
    */
    for (int i = 0; i <= s1.length(); i++) {
        for (int j = 0; j <= s2.length(); j++) {
            // First string is empty -> only option is to insert all characters of the second string into it, making it j operations
            if (i == 0) {
                dp[i][j] = j;
            }
            // Second string is empty -> remove all characters from the first string
            else if (j == 0) {
                dp[i][j] = i;
            }
            // The characters are the same at the position currently being considered in both strings -> no further operations required
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                int temp = min(dp[i][j - 1], dp[i - 1][j]); // The cost of inserting and removing, respectively
                dp[i][j] = 1 + min(temp, dp[i - 1][j - 1]); // The minimum cost of inserting, removing (stored in temp), or replacing
            }
        }
    }
    cout << dp[s1.length()][s2.length()];
    return 0;
}