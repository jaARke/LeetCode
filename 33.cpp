#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        if (nums.front() > target) {
            int k = nums.size() - 1;
            while (i < k && nums[i] > target) { // Move the low pointer to somewhere in the middle
                int mid = (i + k) / 2;
                if (nums[mid] < target) {
                    i = mid;
                }
                else if (nums[mid] > target) {
                    if (nums[mid] >= nums[i]) {
                        i = mid + 1;
                    }
                    else {
                        k = mid - 1;
                    }
                }
                else {
                    return mid;
                }
            }
        }
        if (nums.back() < target) { // Move the high pointer to somewhere in the middle
            int k = 0;
            while (j > k && nums[j] < target) {
                int mid = (j + k) / 2;
                if (nums[mid] > target) {
                    j = mid;
                }
                else if (nums[mid] < target) {
                    if (nums[mid] <= nums[j]) {
                        j = mid - 1;
                    }
                    else {
                        k = mid + 1;
                    }
                }
                else {
                    return mid;
                }
            }
        }
        while (i < j) { // Run binary search now that the pointers are in their correct positions
            int mid = (i + j) / 2;
            if (nums[mid] > target) {
                j = mid - 1;
            }
            else if (nums[mid] < target) {
                i = mid + 1;
            }
            else {
                return mid;
            }
        }
        return nums[i] == target ? i : -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3};
    int target = 1;
    cout << s.search(nums, target) << endl;
    return 0;
}