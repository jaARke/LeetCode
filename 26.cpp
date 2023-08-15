#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0];
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            while (nums[i] == prev) {
                if (++i >= nums.size()) {
                    return k;
                }
            }
            nums[k++] = nums[i];
            prev = nums[i];
        }
        return k;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}