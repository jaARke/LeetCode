#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            while (!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        res.push_back(nums[window.front()]);

        for (int i = k; i < nums.size(); i++) {
            while (!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);

            if (i - window.front() >= k) {
                window.pop_front();
            }
            res.push_back(nums[window.front()]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,-1};
    int k = 1;
    auto ans = s.maxSlidingWindow(nums, k);
    cout << "Done" << endl;
    return 0;
}
