#include <vector>

using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums), end(nums));
        int l = 0, r = nums[nums.size() - 1] - nums[0];
        while (l < r) {
            int count = 0;
            int m = (l + r) / 2;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i + 1] - nums[i] <= m) {
                    i++;
                    count++;
                }
            }
            if (count >= p) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }
};