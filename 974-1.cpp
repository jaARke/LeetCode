#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        unordered_map<int, int> count;
        count[0] = 1;
        int res = 0;
        for (int x : prefix) {
            int mod = ((x % k) + k) % k;
            res += count[mod];
            count[mod]++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 2, 9};
    int k = 2;

    cout << s.subarraysDivByK(nums, k) << endl;
    return 0;
}