#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1; // i is the low index, j is the high
        while (i < j) {
            int mid = (i + j) / 2;  // Mid = the average index of high and low
            // Since we already check for nums[mid] == target, we can skip over the mid element when updating i and j
            if (nums[mid] < target) {
                i = mid + 1;
            }
            else if (nums[mid] > target) {
                j = mid - 1;
            }
            else {
                return mid;
            }
        }
        return nums[i] == target ? i : -1;  // Nums[i] == nums[j] because i == j, and nums[i] must equal target, or it cannot be found
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    cout << s.search(nums, 2) << endl;
    return 0;
}