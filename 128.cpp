#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end() ), nums.end() );
        int prev = nums[0];
        int res = 1;
        int curr = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (prev == nums[i] - 1) {
                curr++;
            }
            else {
                curr = 1;
            }
            prev = nums[i];
            res = max(res, curr);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {100,4,200,1,3,2};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}