#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

/*
 * There are two solutions given below. The first inserts all numbers into a set and then iterates through the set. If
 * the current number has no consecutive number lower than it, we check how many numbers are consecutively greater than it.
 *
 * The second uses sorting and iterates the list afterwards. On paper, the set method has faster runtime, but sorting
 * gives a better result on LeetCode.
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto& x : nums) {
            s.insert(x);
        }
        int result = INT32_MIN;
        for (auto& x : s) {
            if (s.find(x - 1) == s.end()) { // This is the lowest number of this possible sequence
                int curr = x;
                int length = 1;
                while (s.find(curr + 1) != s.end()) {
                    length++;
                    curr++;
                }
                result = max(result, length);
            }
        }
        return result;
    }
};

/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end() ), nums.end() );
        int prev = nums[0];
        int res = 1;
        int curr = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (prev == nums[i] - 1) {
                curr++;
            }
            else {
                curr = 1;
            }
            prev = nums[i];
            res = max(res, curr);
        }
        return res;
    }
};
 */

int main() {
    Solution s;
    vector<int> nums = {100,4,200,1,3,2};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}