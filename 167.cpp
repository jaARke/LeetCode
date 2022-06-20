#include <vector>

using namespace std;

/*
 * Process is very similar to three-sum, where you use two pointers to locate the two elements that add up to a given value.
 * The only difference here is that you don't have a third pointer to worry about.
 * If the current sum is greater than the target, decrement the pointer at the large end of the list. If the current sum
 * is less, increment the pointer at the low end of the list.
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            int curr = numbers[i] + numbers[j];
            if (curr == target) {
                return {i + 1, j + 1};
            }
            else if (curr > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return {};
    }
};