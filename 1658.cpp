#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> m;
        int res = INT32_MAX, currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            if (x - currSum == 0) {
                res = min(res, i + 1);
            }
            else if (x - currSum > 0) {
                m[x - currSum] = i + 1;
            }
            else break;
        }

        currSum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            currSum += nums[i];
            if (x - currSum < 0) break;
            else if (x - currSum == 0) {
                res = min(res, (int)nums.size() - i);
            }
            else if (m.find(currSum) != m.end() && m[currSum] + ((int)nums.size() - i) < nums.size()) {
                res = min(res, m[currSum] + ((int)nums.size() - i));
            }
        }
        return (res == INT32_MAX ? -1 : res);
    }
};
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0;
        for (int i : nums) {
            target += i;
        }
        target -= x;
        if (target < 0) {
            return -1;
        }

        int currSum = 0, maxLen = INT32_MIN;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            currSum += nums[r];
            while (currSum > target) {
                currSum -= nums[l++];
            }
            if (currSum == target) {
                maxLen = max(maxLen, (r - l) + 1);
            }
        }
        return (maxLen == INT32_MIN ? -1 : nums.size() - maxLen);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1};
    int x = 3;
    cout << s.minOperations(nums, x) << endl;
    return 0;
}