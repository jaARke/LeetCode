#include <vector>
#include <iostream>

using namespace std;

/*
 * Can't use division. This method calculates prefix and suffix arrays. The prefix array gives the cumulative product moving
 * forward up to a certain index and the suffix array gives the cumulative product moving backwards up to a certain index.
 * O(n) time, O(n) space.
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size());
        vector<int> suf(nums.size());
        pre[0] = 1;
        suf[nums.size() - 1] = 1;
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] * nums[i + 1];
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(pre[i] * suf[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1,1,0,-3,3};
    auto res = s.productExceptSelf(nums);
    cout << "test" << endl;
    return 0;
}