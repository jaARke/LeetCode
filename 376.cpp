#include <vector>
#include <algorithm>

using namespace std;

/*
This problem is better known as the longest alternating subsequence. You keep track of count1 (the length of the longest alternating subsequence with last value less than previous), and count2
(the length of the longest alternating subsequence with last value greater than previous). When you find an array element that is smaller than the one before it, you set count1 to be equal to count2 + 1, and
vice versa for count2. This is an easier alternative than the dp solution.
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                count1 = count2 + 1;
            }
            if (nums[i] > nums[i - 1]) {
                count2 = count1 + 1;
            }
        }
        return max(count1, count2) + 1;
    }
};
