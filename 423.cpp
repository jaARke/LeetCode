#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


/*
 * The following solutions represents my first attempt. I'm not exactly sure why it didn't pass, but the idea is simple.
 * Take frequencies of each character in s, then go through digits 0-9 checking if the digit can be spelled with the current
 * frequency values. If it can, decrement all of its letters' frequencies and add it to the result string. Repeat until there
 * are no more characters in the frequency map. Sort the res string and return.
 *
class Solution {
public:
    string originalDigits(string s) {
        string res = "";
        unordered_map<char, int> freq;
        vector<pair<string, int>> digits = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
        for (auto& c : s) {
            freq[c]++;
        }
        while (!digits.empty()) {
            for (auto iter = digits.begin(); iter != digits.end();) {
                int j = 0;
                while (j < iter->first.length() && freq[iter->first[j]] > 0) {
                    j++;
                }
                if (j == iter->first.length()) {
                    for (auto& c : iter->first) {
                        freq[c]--;
                    }
                    res += to_string(iter->second);
                    iter++;
                }
                else {
                    iter = digits.erase(iter);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
*/

/*
 * The following solution seems naive at first. We consider the digits that have a letter that is only used by them.
 * We can know the number of times to add these characters to the result straight away. We use those results to find
 * the frequencies of the other characters in the result string, since we know the remaining characters must be used
 * by those not already considered.
 */
class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> freqs;
        for (auto& c : s) {
            freqs[c]++;
        }

        vector<int> resVec(10,0);
        resVec[0] = freqs['z'];
        resVec[2] = freqs['w'];
        resVec[4] = freqs['u'];
        resVec[6] = freqs['x'];
        resVec[8] = freqs['g'];
        resVec[1] = freqs['o'] - resVec[2] - resVec[4] - resVec[0];
        resVec[3] = freqs['h'] - resVec[8];
        resVec[5] = freqs['f'] - resVec[4];
        resVec[7] = freqs['s'] - resVec[6];
        resVec[9] = resVec['i'] - resVec[8] - resVec[6] - resVec[5];

        string res = "";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < resVec[i]; j++) {
                res += to_string(i);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.originalDigits("owoztneoer") << endl;
    return 0;
}