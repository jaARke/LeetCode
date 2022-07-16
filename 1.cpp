#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diffMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (diffMap.find(nums[i]) != diffMap.end()) {
                result.push_back(diffMap.at(nums[i]));
                result.push_back(i);
                return result;
            }
            else {
                diffMap[target - nums[i]] = i;
            }
        }
        return result;
    }
};