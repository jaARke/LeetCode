#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

/*
This question is very similar to the original combination sum problem. The only difference being that idx is incremented before the recursive call (because the same element can't be used more than once),
and duplicated elements are skipped as the comment specifies.
*/

class Solution {
private:
    void RecursiveHelper(vector<int>& candidates, int target, vector<int>& included, vector<vector<int>>& res,  int idx) {
        if (target == 0) {  
            res.push_back(included);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (target - candidates[i] < 0) {  
                break;
            }
            if (i != idx && candidates[i] == candidates[i - 1]) {   // Skip duplicate elements -> they will given duplicate combinations and are already being considered when i == idx
                continue;
            }
            included.push_back(candidates[i]);
            RecursiveHelper(candidates, target - candidates[i], included, res, i + 1);
            included.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> included;
        vector<vector<int>> res;
        RecursiveHelper(candidates, target, included, res, 0);
        return res;
    }
};