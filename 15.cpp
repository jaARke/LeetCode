#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < nums.size(); i++) {
            int currTarg = 0 - nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int currSum = nums[j] + nums[k];
                if (currSum == currTarg) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (currSum > currTarg) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        vector<vector<int>> res;
        for (auto& x : s) {
            res.push_back(x);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto res = s.threeSum(nums);
    cout << "Done!" << endl;
    return 0;
}