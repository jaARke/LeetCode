#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
private:
    /*
     * The following backtracking function executes the two possibilities we have at each position:
     *  - Take the current element as part of the subsequence (if it is less than the last element of curr)
     *  - Don't take the current element as part of the subsequence
     *  We check to take it first. If we can, we begin a new recursive chain. After this chain executes, we remove the
     *  new element and then execute the chain associated with not taking it.
     */
    void recHelper(int idx, vector<int>& nums, vector<int>& curr, set<vector<int>>& s) {
        if (idx == nums.size()) {
            if (curr.size() > 1) {
                s.insert(curr);
            }
            return;
        }
        // Take the element at the current idx
        if (curr.empty() || nums[idx] >= curr.back()) {
            curr.push_back(nums[idx]);
            recHelper(idx + 1, nums, curr, s);
            curr.pop_back();
        }
        // Don't take the element at the current idx
        recHelper(idx + 1, nums, curr, s);
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> curr = {};
        recHelper(0, nums, curr, s);
        return {s.begin(), s.end()};
    }
};

/*
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> res;
        for (auto& x : nums) {
            vector<vector<int>> add;
            for (auto& y : s) {
                if (y.back() <= x) {
                    vector<int> temp = y;
                    temp.push_back(x);
                    add.push_back(temp);
                }
            }
            for (auto& y : add) {
                s.insert(y);
            }
            s.insert({x});
        }
        for (auto& x : s) {
            if (x.size() > 1) {
                res.push_back(x);
            }
        }
        return res;
    }
};
 */

int main() {
    Solution s;
    vector<int> nums = {4,6,7,7};
    auto res = s.findSubsequences(nums);
    cout << "Done!" << endl;
    return 0;
}