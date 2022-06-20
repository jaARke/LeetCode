#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
 * Two-pointer loop solution
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long currTarget = target - nums[i] - nums[j];
                int k = j + 1, q = nums.size() - 1;
                while (k < q) {
                    if (nums[k] + nums[q] == currTarget) {
                        s.insert({nums[i], nums[j], nums[k], nums[q]});
                        q--;
                        k++;
                    }
                    else if (nums[k] + nums[q] > currTarget) {
                        q--;
                    }
                    else  {
                        k++;
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