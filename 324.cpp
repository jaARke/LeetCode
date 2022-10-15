#include <vector>
#include <algorithm>

using namespace std;

/*
Sort the list and split it in the middle. Start from the end of the greater list and fill in the result's peak entries (odd indices). Then, start from the end of the smaller list and fill in the valley entries (even indices).
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        sort(nums.begin(), nums.end());
        vector<int> res(nums.size());
        for (int i = 1, j = nums.size() - 1; i < nums.size(); i += 2, j--) {
            res[i] = nums[j];
        }
        for (int i = 0, j = (nums.size() % 2 == 0 ? (nums.size() / 2) - 1 : nums.size() / 2); i < nums.size(); i += 2, j--) {
            res[i] = nums[j];
        }
        nums = res;
    }
};