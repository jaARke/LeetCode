#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * For this question, we use the DP algorithm for longest common subsequence. We iterate through word1 in the outer loop
 * and word2 in the inner loop. When we come across matching letters, we set dp[i][j] = dp[i - 1][j - 1] + 1. If letters
 * do not match, we set dp[i][j] to the maximum of dp[i][j - 1] and dp[i - 1][j].
 *
 * dp[i][j] is the value of the longest common subsequence with up to i indices considered from word1 and up to j indices
 * considered from word2. When the letters of word1 and word2 match, we increment the value of dp from considering one less
 * index in both strings -> the value at dp[i - 1][j - 1]. When the letters do not match, we take the maximum dp value from
 * one of two cases: when one less index was considered in word1 (dp[i - 1][j]) or when one less index was considered in word2
 * (dp[i][j - 1]).
 *
 * The longest common subsequence length is given when all indices of word1 and word2 have been considered:
 * dp[word1.length()][word2.length()]
 * To find the answer we do word1.length() + word2.length() - 2*(length of longest common subsequence)
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return ((int) word1.length() - dp[word1.length()][word2.length()]) + ((int) word2.length() - dp[word1.length()][word2.length()]);
    }
};