#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void recHelper(vector<int>& curr, vector<int>& nums, vector<bool>& seen, vector<vector<int>>& res) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!seen[i]) {
                seen[i] = true;
                curr.push_back(nums[i]);
                recHelper(curr, nums, seen, res);
                seen[i] = false;
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> seen(nums.size(), false);
        vector<vector<int>> res;
        recHelper(curr, nums, seen, res);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    auto res = s.permute(nums);
    cout << "Done!" << endl;
    return 0;
}