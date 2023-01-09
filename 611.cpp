#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * Calling the side lengths s1, s2, and s3... we know for a valid triangle with s1 and s2, s3 must be less than the sum
 * s1 + s2. Thus, for every distinct combination of two numbers in nums, we find all the numbers that are less than their sum.
 *
 * We can do this in two ways. Both require step-iterating nums with i and j.
 *
 * In the first, we search [j + 1, end] for the first num equal or greater to nums[i] + nums[j].
 * We use binary search for this.
 *
 * In the second, we also search [j + 1, end] for the first num equal or greater to nums[i] + nums[j]. The difference
 * here is we remember the position and use it as the starting point in our search on the next value of j. This works
 * because nums[i] + nums[j] will always increase as we iterate j, and thus we know all values already considered satisfy
 * the requirement. We only need to consider higher nums[k] values as we iterate j.
 * In the previous method, this is the same as remembering the position returned by binary search and using it as the
 * lower bound in the next search. In this way, we narrow down our search space while we execute the inner loop.
 */


/*
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                auto iter = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
                res += iter - nums.begin() - j - 1;
            }
        }
        return res;
    }
};
 */

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.size() && nums[i] != 0; j++) {
                while (k < nums.size() && nums[k] < nums[i] + nums[j]) {
                    k++;
                }
                res += k - j - 1;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,3,4};
    cout << s.triangleNumber(nums) << endl;
    return 0;
}