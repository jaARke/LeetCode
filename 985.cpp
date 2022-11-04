#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int currSum = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                currSum += nums[i];
            }
        }
        for (int i = 0; i < queries.size(); i++) {
            if (nums[queries[i][1]] % 2 == 0) {
                if (queries[i][0] % 2 == 0) {
                    currSum += queries[i][0];
                }
                else {
                    currSum -= nums[queries[i][1]];
                }
            }
            else if (queries[i][0] % 2 != 0) {
                currSum += nums[queries[i][1]] + queries[i][0];
            }
            nums[queries[i][1]] += queries[i][0];
            res.push_back(currSum);
        }
        return res;
    }
};