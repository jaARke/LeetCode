#include <vector>
#include <algorithm>

using namespace std;

/*
 * Very similar to 3Sum and 4Sum, but you also have to keep track of the sum that is closest to the target value. This is
 * done with variables storing the closest sum and the difference between that sum and the target.
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result, diff = INT32_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int temp = nums[i] + nums[j] + nums[k];
                // Check if the current smallest difference should be updated with the values currently being considered
                if (abs(target - temp) < diff) {
                    diff = abs(target - temp);
                    result = temp;
                }
                // See which pointers should be incremented or decremented based on the difference between the target and temp
                if (temp == target) {
                    return temp;
                }
                else if (temp > target) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return result;
    }
};