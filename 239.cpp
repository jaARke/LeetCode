#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> res;
        int i = 0, j = 0;
        while (j < k) {
            while (!d.empty() && nums[d.back()] <= nums[j]) {
                d.pop_back();
            }
            d.push_back(j);
            j++;
        }
        while (j < nums.size()) {
            res.push_back(nums[d.front()]);
            if (d.front() == i) {
                d.pop_front();
            }
            while (!d.empty() && nums[d.back()] <= nums[j]) {
                d.pop_back();
            }
            d.push_back(j);
            i++;
            j++;
        }
        res.push_back(nums[d.front()]);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    auto ans = s.maxSlidingWindow(nums, k);
    cout << "Done" << endl;
    return 0;
}
