#include <bits/stdc++.h>

using namespace std;

/*
The maximum subarray sum will be one of the following:
    - The single highest value element
    - The highest value subarray of the original (non-circular) array
    - The total sum of the original array after taking out the minimum value subarray
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum = INT32_MAX, maxSum  = INT32_MIN, minCurr = 0, maxCurr = 0, totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            minCurr = min(nums[i], minCurr + nums[i]);
            maxCurr = max(nums[i], maxCurr + nums[i]);
            minSum = min(minSum, minCurr);
            maxSum = max(maxSum, maxCurr);
            totalSum += nums[i];
        }
        if (minSum == totalSum) {   // The entire array is negative -> get the highesy single value
            return maxSum;
        }
        // Else, there is some non-negative piece of the array we want to use as an answer -> could be the maxSum of the original array, or the total sum of the original array excluding the subarray with minimum sum
        return max(maxSum, totalSum - minSum);
    }
};

int main() {
    Solution s;
    vector<int> nums = {9, -3, -4, -2, 5, 6, -7};
    cout << s.maxSubarraySumCircular(nums) << endl;
    return 0;
}