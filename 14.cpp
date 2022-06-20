#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < res.size() && j < strs[i].size() && strs[i][j] == res[j]) {
                j++;
            }
            res = res.substr(0, j);
            if (res == "") {
                return res;
            }
        }
        return res;
    }
};