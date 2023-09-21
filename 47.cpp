#include <vector>
#include <iostream>
#include <set>

using namespace std;

/*
class Solution {
private:
    void recHelper(string& curr, vector<int>& nums, vector<bool>& seen, vector<vector<int>>& res, unordered_set<string>& uniq) {
        if (uniq.find(curr) != uniq.end()) {
            return;
        }
        uniq.insert(curr);
        if (curr.length() == nums.size()) {
            res.emplace_back(curr.begin(), curr.end());
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!seen[i]) {
                seen[i] = true;
                curr.push_back(nums[i]);
                recHelper(curr, nums, seen, res, uniq);
                seen[i] = false;
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        string curr;
        vector<bool> seen(nums.size(), false);
        vector<vector<int>> res;
        unordered_set<string> uniq;
        recHelper(curr, nums, seen, res, uniq);
        return res;
    }
};
 */

class Solution {
private:
    void recHelper(int i, vector<int>& nums, vector<vector<int>>& res, set<vector<int>>& unique) {
        if (i == nums.size() && unique.find(nums) == unique.end()) {
            unique.insert(nums);
            res.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            if (i != j && nums[i] == nums[j]) continue;
            swap(nums[i], nums[j]);
            recHelper(i + 1, nums, res, unique);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> unique;
        vector<vector<int>> res;
        recHelper(0, nums, res, unique);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    auto res = s.permuteUnique(nums);
    cout << "Done!" << endl;
    return 0;
}