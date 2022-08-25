#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;
        int j = 1;
        int curr = nums[i];
        int res = (curr < k ? 1 : 0);
        while (j < nums.size()) {
            curr *= nums[j];
            while (curr >= k && i != j) {
                curr /= nums[i++];
            }
            if (curr < k) {
                res += (j - i) + 1; // Accounts for every interior subarray
            }
            j++;
        }
        return res;
    }
};

/*
Brute Force solution -> gives TLE
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k) {
                res++;
            }
            int j = i - 1;
            int temp = nums[i];
            while (j >= 0 && nums[j] * temp < k) {
                temp *= nums[j--];
                res++;
            }
        }
        return res;
    }
};
*/