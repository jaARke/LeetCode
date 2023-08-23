#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    vector<vector<char>> digitToChar = {
            {},
            {},
            {'a','b','c'},
            {'d','e','f'},
            {'g','h','i'},
            {'j','k','l'},
            {'m','n','o'},
            {'p','q','r','s'},
            {'t','u','v'},
            {'w','y','x','z'}
    };
private:
    void recHelper(int i, string& digits, string& ans, vector<string>& res) {
        if (i >= digits.length()) {
            res.push_back(ans);
            return;
        }
        for (auto& c : digitToChar[digits[i] - '0']) {
            ans.push_back(c);
            recHelper(i + 1, digits, ans, res);
            ans.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> res;
        string ans;
        recHelper(0, digits, ans, res);
        return res;
    }
};

int main() {
    Solution s;
    string digits = "23";
    auto res = s.letterCombinations(digits);
    cout << "Done!" << endl;
    return 0;
}