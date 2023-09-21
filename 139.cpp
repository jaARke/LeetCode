#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> lookup(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i && !dp[i]; j++) {
                dp[i] = dp[j] && lookup.find(s.substr(j, i - j)) != lookup.end();
            }
        }
        return dp[s.length()];
    }
};

int main() {
    Solution s;
    string str = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    cout << s.wordBreak(str, wordDict) << endl;
    return 0;
}