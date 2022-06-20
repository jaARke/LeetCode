#include <vector>
#include <iostream>

using namespace std;

/*
 * This solution doesn't meet the requirement of running in O(log(m + n)) time, but it is a lot simpler. Just iterate
 * for half of the combined size of the arrays, checking which array element is smaller. Assign this one to curr.
 * There are two cases at the end: either the combined array has odd size--in which case curr is the answer--or it has even
 * size and the average of curr and its previous value is the answer. Hence, the use of the prev variable. Also note that
 * this variable is updated at the beginning of the loop to ensure it is actually different from curr on exit.
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int prev = 0, curr = 0, n1 = 0, n2 = 0;
        for (int i = 0; i <= (nums1.size() + nums2.size()) / 2; i++) {
            prev = curr;
            if (n1 >= nums1.size()) {
                curr = nums2[n2];
                n2++;
            }
            else if (n2 >= nums2.size()) {
                curr = nums1[n1];
                n1++;
            }
            else if (nums1[n1] < nums2[n2]) {
                curr = nums1[n1];
                n1++;
            }
            else {
                curr = nums2[n2];
                n2++;
            }
        }
        if ((nums1.size() + nums2.size()) % 2 == 0) {
            return ((double)curr + (double)prev) / 2;
        }
        else {
            return curr;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
