#include <string>

using namespace std;

/*
 * Iterate through the characters, trying to expand into a palindrome around each one.
 * This algorithm could be made faster by passing lengths and centers around and recreating the string at the end,
 * but this works.
 */

class Solution {
private:
    string expand(string& s, int left, int right) {
        string res = "";
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            res.push_back(s[right]);
            if (left != right) {
                res.insert(res.begin(), s[left]);
            }
            left--;
            right++;
        }
        return res;
    }
public:
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            string curr = expand(s, i, i);
            if (curr.length() > res.length()) {
                res = curr;
            }
            curr = expand(s, i,i + 1);
            if (curr.length() > res.length()) {
                res = curr;
            }
        }
        return res;
    }
};