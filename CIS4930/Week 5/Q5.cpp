#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> prevWords;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashDict(wordDict.begin(), wordDict.end());
        vector<string> ans;

        // Bases cases: the string has already been considered or the string is empty
        if (prevWords.find(s) != prevWords.end()) {
            return prevWords[s];
        }
        if (s.empty()) {
            ans.push_back("");
            prevWords[""] = ans;
            return ans;
        }
        
    
        for (int i = 0; i < s.length(); i++) {
            string sub = s.substr(0, i + 1);
            if (hashDict.find(sub) != hashDict.end()) {
                string next = s.substr(i + 1);
                vector<string> split = wordBreak(next, wordDict);
                for (int j = 0; j < split.size(); j++) {
                    if (!split[j].empty()) {
                        ans.push_back(sub + " " + split[j]);
                    }
                    else {
                        ans.push_back(sub);
                    }
                }
            }
        }
        prevWords[s] = ans;
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> dict{"cat", "cats", "and", "sand", "dog"};

    auto result = s.wordBreak("catsanddog", dict);
    return 0;
}