#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {    // Violation detected
                if (flag) { // Only one violation allowed
                    return false;
                }
                /*
                 * Cases where the previous number should conform to the current (which is less):
                 * The current number is the second in the list OR the number before the previous goes in a
                 * non-decreasing series with the current.
                 */
                if (i == 1 || nums[i - 2] <= nums[i]) {
                    nums[i - 1] = nums[i];
                }
                /*
                 * If the above cases do not apply (i.e., the number before the previous is greater than the current
                 * and thus cannot form a non-decreasing series with it) the current should conform to the previous
                 * element.
                 */
                else {
                    nums[i] = nums[i - 1];
                }
                /*
                 * These cases can be simplified by noticing that updating the previous element does nothing for us,
                 * as it will never bee looked at again. I have kept it this way for readability, but instead of the if-
                 * else block shown above, we could write:
                 *
                 *   if (i != 1 && nums[i - 2] > nums[i]) { // Cases where the previous number should conform to the current
                 *      nums[i] = nums[i - 1];
                 *   }
                 */
                flag = true;
            }
        }
        return true;
    }
};

/*
 * This is a solution based on the fact that an LIS of nums will be greater than or equal to the size of nums if
 * we should return true.
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int> lis;
        for (auto& x : nums) {
            auto iter = upper_bound(lis.begin(), lis.end(), x);
            if (iter == lis.end()) {
                lis.push_back(x);
            }
            else {
                *iter = x;
            }
        }
        return lis.size() >= nums.size() - 1;
    }
};
 */