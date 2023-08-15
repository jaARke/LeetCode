#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currSum = 0;
        int res = nums.size();
        int i = 0, j = 0;

        for (; i < nums.size(); i++) {
            currSum += nums[i];
            while (currSum - nums[j] >= target) {
                currSum -= nums[j];
                j++;
            }
            if (currSum >= target) {
                res = min(i - j + 1, res);
            }
        }
        if (res == nums.size() && currSum < target) {
            return 0;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {12,28,83,4,25,26,25,2,25,25,25,12};
    cout << s.minSubArrayLen(213, nums) << endl;
}