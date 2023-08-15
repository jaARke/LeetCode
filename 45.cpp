#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int currIdx = 0, currMoves = 0, nextIdx = 0;

        for (int i = 0; i < nums.size() && currIdx < nums.size() - 1; i++) {
            nextIdx = max(nextIdx, i + nums[i]);

            if (currIdx == i) {
                currIdx = nextIdx;
                currMoves++;
            }
        }
        return currMoves;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    cout << s.jump(nums) << endl;
    return 0;
}