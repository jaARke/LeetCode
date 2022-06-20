#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * For this problem, we iterate through the string and keep a start variable as we do it. We use a map to keep track
 * of the characters we've seen and the last index we saw them at. When we encounter a character we've already seen, we
 * assign start to be (the position of the previous occurrence plus one) BUT only if start is not already greater than that
 * character's position. In this way, we don't have to worry about deleting characters from the map everytime we update
 * start -> we just always move it to the greatest position in which no repeats occur. We know that if start is
 * already greater than where we would have moved it, there is no worry of there being a double in the current window
 * anyway.
 * For each pass we also take the max of result and the current distance between start and the iterator.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 1) {
            return 1;
        }
        int result = 0;
        int start = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) != m.end()) {
                start = max(start, m[s[i]] + 1);    // Only move forwards
            }
            m[s[i]] = i;
            result = max(result, i - start + 1);
        }
        return result;
    }
};

int main() {
    Solution s;
    string st = "abba";
    cout << s.lengthOfLongestSubstring(st) << endl;
    return 0;
}