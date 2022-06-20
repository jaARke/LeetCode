#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
 * Binary search solution
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    long long currTarget = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];
                    auto found = lower_bound(nums.begin() + k + 1, nums.end(), currTarget);
                    if (found != nums.end() && *found == currTarget) {
                        s.insert({nums[i], nums[j], nums[k], *found});
                    }
                }
            }
        }
        for (auto& x : s) {
            result.push_back(x);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,0,0,0};
    int target = 0;
    auto result = s.fourSum(nums, target);
    return 0;
}