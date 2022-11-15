#include <vector>
#include <iostream>

using namespace std;

/*
 * Floyd's Tortoise & Hare algorithm for cycle detection.
 * Read here: https://medium.com/@divyanshpandey99/using-floyds-tortoise-and-hare-algorithm-on-and-beyond-linked-list-86ad0f5cc213
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};

/*
 * Two pieces of key insight:
 * The array can only hold values between 1 and n (size of the array) and cannot hold any duplicates. This means that
 * it must hold every value between 1 and n except for one. It also means that for each index i in nums, there will be
 * exactly i numbers in the list <= i. This holds true until we get to the repeat value.
 *
 * We search the array's index positions, looking for the first index for which there are more <= elements than the
 * index value.
 *
class Solution {
private:
    bool count(int mid, vector<int>& nums) {
        int count = 0;
        for (auto& x : nums) {
            if (x <= mid) {
                count++;
            }
        }
        return count > mid;
    }
public:
    int findDuplicate(vector<int>& nums) {
        int i = 1, j = nums.size();
        int res = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (count(mid, nums)) {
                j = mid - 1;
                res = mid;
            }
            else {
                i = mid + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {};
}
*/