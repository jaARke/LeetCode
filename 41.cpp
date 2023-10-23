#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int res = 1;
        for (int i : nums) {
            if (i == res) res++;
        }
        return res;
    }
};
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool hasOne = false;
        for (int i = 0; i < nums.size() && !hasOne; i++) {
            if (nums[i] == 1) hasOne = true;
        }
        if (!hasOne) return 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums.size() || nums[i] <= 0) nums[i] = 1;
        }

        for (int i = 0; i < nums.size(); i++) {
            int a = abs(nums[i]);
            nums[a % nums.size()] = -abs(nums[a % nums.size()]);
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) return i;
        }
        return (nums[0] > 0 ? nums.size() : nums.size() + 1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,0};
    cout << s.firstMissingPositive(nums) << endl;
    return 0;
}