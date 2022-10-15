#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currSumMin = nums[0];
        int currSumMax = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(currSumMax, currSumMin);
            }
            currSumMax = max(currSumMax * nums[i], nums[i]);
            currSumMin = min(currSumMin * nums[i], nums[i]);
            maxSum = max(maxSum, currSumMax);
        }
        return maxSum;
    }
};