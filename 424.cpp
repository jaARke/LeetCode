#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * If the size of the window minus the frequency of the most common character in the window is greater than k, we know
 * there is no way to replace elements to make a repeating substring which is the entire size of the window.
 * We never shrink the window - only make it larger. This is because the largest window represents an answer, and only
 * lengthening will change the answer. Thus, we can keep using outdated freq values and window sizes until we have
 * a window which properly overwrites them.
 *
 * See https://leetcode.com/problems/longest-repeating-character-replacement/discuss/2053753/PLEASE-READKey-observation-on-why-the-O(N)-solution-works-without-O(26)-getMax
 * for a more detailed explanation on this algorithm.
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int i = 0, j = 0, res = 0, freq = 0;
        while (j < s.length()) {
            m[s[j]]++;
            freq = max(freq, m[s[j]]);
            j++;
            if (j - i - freq <= k) {
                res = max(res, j - i);
            }
            else {
                m[s[i]]--;
                i++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string st = "AABABBA";
    int k = 1;
    cout << s.characterReplacement(st, k) << endl;
    return 0;
}