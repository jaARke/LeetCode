#include <bits/stdc++.h>

using namespace std;

/*
We know that a subbaray sum between i and j is divisible by k if (prefixSum[i] - prefixSum[j]) % k == 0. This condition is equal to: prefixSum[i] % k == prefixSum[j] % k. We also know that a subarray sum between 0 and i
is divisible by k if prefixSum[i] % k. We iterate through nums and keep track of a prefixSum. We add to the answer the number of times the prefixSum remainder has been seen before AND whether or not the prefixSum
is divisible by k. Then, we increment the frequency of the current prefixSum remainder.

The ((preSum % k) + k) % k is a way to take a true modulus of a negative number. Consider -3 % 8. The answer is -3 = (8)(-1) + 5, but C++ will give us -3. 
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> rems(k, 0);
        int preSum = 0, count = 0;
        for (auto& x : nums) {
            preSum += x;
            count += rems[((preSum % k) + k) % k] + (preSum % k == 0 ? 1 : 0);
            rems[((preSum % k) + k) % k]++;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    cout << s.subarraysDivByK(nums, k) << endl;
    return 0;
}