#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<string> res;
        int curr = nums[0];
        string currStr = "";
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                currStr = to_string(curr);
                if (curr != nums[i - 1]) {
                    currStr += "->";
                    currStr += to_string(nums[i - 1]);
                }
                res.push_back(currStr);
                curr = nums[i];
            }
        }
        currStr = to_string(curr);
        if (curr != nums.back()) {
            currStr += "->";
            currStr += to_string(nums.back());
        }
        res.push_back(currStr);
        return res;
    }
};