#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

/*
 * For each word compute all suffixes and try to remove them from the list of words. The remaining words will need to be
 * turned into the string so go through them and count their lengths.
 */

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0;
        unordered_set<string> leftover(words.begin(), words.end());
        for (auto& x : words) {
            for (int i = 1; i < x.length(); i++) {
                leftover.erase(x.substr(i));
            }
        }
        for (auto& x : leftover) {
            res += x.length() + 1;
        }
        return res;
    }
};