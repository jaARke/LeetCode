#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int low = INT32_MAX, mid = INT32_MAX;
        for (int x : nums) {
            if (x > mid) return true;

            if (x > low && x < mid) mid = x;
            else if (x < low) low = x;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,4,3,2,1};
    cout << s.increasingTriplet(nums) << endl;
    return 0;
}