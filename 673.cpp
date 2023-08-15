#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> lengths(nums.size(), 1);
        vector<int> counts(nums.size(), 1);
        int currMax = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (lengths[i] < lengths[j] + 1) {
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                        currMax = max(lengths[i], currMax);
                    }
                    else if (lengths[i] == lengths[j] + 1) {
                        counts[i] += counts[j];
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (lengths[i] == currMax) {
                res += counts[i];
            }
        }
        return res;
    }
};