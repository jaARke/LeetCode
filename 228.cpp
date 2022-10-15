#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        int back = nums[0];
        int prev = nums[0];
        vector<string> res;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - 1 != prev) {
                if (prev == back) {
                    res.push_back(to_string(back));
                }
                else {
                    res.push_back(to_string(back) + "->" + to_string(prev));
                }
                back = nums[i];
            }
            prev = nums[i];
        }
        if (back != prev) {
            res.push_back(to_string(back) + "->" + to_string(prev));
        }
        else {
            res.push_back(to_string(back));
        }
        return res;
    }
};