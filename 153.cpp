#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] > nums[j]) {
                i = mid + 1;
            }
            else {
                j = mid;
            }
        }
        return nums[i];
    }
};

int main() {
    Solution s;
    vector<int> nums = {11,13,15,17};
    cout << s.findMin(nums) << endl;
    return 0;
}