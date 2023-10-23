#include <bits/stdc++.h>

using namespace std;

int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k, j = k;
        int currMin = nums[k];
        int res = nums[k];
        while (i > 0 && j < nums.size() - 1) {
            if (nums[i - 1] > nums[j + 1]) {
                i--;
                currMin = min(currMin, nums[i]);
            }
            else {
                j++;
                currMin = min(currMin, nums[j]);
            }
            res = max(res, currMin * (j - i + 1));
        }
        while (i > 0) {
            i--;
            currMin = min(currMin, nums[i]);
            res = max(res, currMin * (j - i + 1));
        }
        while (j < nums.size() - 1) {
            j++;
            currMin = min(currMin, nums[j]);
            res = max(res, currMin * (j - i + 1));
        }
        return res;
    }
};