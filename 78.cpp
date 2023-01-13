#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> curr;
            for (auto& x : res) {
                vector<int> temp = {nums[i]};
                temp.insert(temp.begin(), x.begin(), x.end());
                curr.push_back(temp);
            }
            res.insert(res.end(), curr.begin(), curr.end());
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    auto res = s.subsets(nums);
    return 0;
}