#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i <= s.length() / 2; i++) {
            if (s.length() % i != 0) continue;
            string sub = s.substr(0, i);
            int j = i;
            while (j < s.length() && s.substr(j, i) == sub) {
                j += i;
            }
            if (j >= s.length()) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    string str = "abcabcabcabc";
    cout << s.repeatedSubstringPattern(str) << endl;
    return 0;
}