#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

/*
This is a solution using recursive backtracking. The helper function essentially computes the sum of all combinations of the candidate numbers. See this link for a state tree and explanation:
https://leetcode.com/problems/combination-sum/discuss/1777569/FULL-STATE-SPACE-TREE-DIAGRAM-EXPLANATION-oror-Recursion-and-Backtracking-oror-Well-Explained-oror-C%2B%2B
*/

class Solution {
private:
    void RecursiveHelper(vector<int>& candidates, int target, vector<int>& included, vector<vector<int>>& res,  int idx) {
        if (target == 0) {  // A solution has been found
            res.push_back(included);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (target - candidates[i] < 0) {   // Since the list is sorted, we know that reaching a number which puts us past the target means we need not consider anymore numbers
                break;
            }
            // Add the candidate to included for the function call
            included.push_back(candidates[i]);
            RecursiveHelper(candidates, target - candidates[i], included, res, i);
            // Remove the candidate from included after the function call -> that specific combination has been tried
            included.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> included;
        vector<vector<int>> res;
        RecursiveHelper(candidates, target, included, res, 0);
        return res;
    }
};