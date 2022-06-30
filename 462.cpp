#include <vector>
#include <algorithm>

using namespace std;

/*
 * Find the median, sum the absolute value differences from the median
 */

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + (nums.size() / 2), nums.end());
        int median = nums[nums.size() / 2];
        int res = 0;
        for (auto& x : nums) {
            res += abs(median - x);
        }
        return res;
    }
};