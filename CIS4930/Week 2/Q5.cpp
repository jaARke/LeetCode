#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> maxList;
        int left = 0;
        int right = k - 1;
        for (int i = 0; i < k; i++) {
            while (!maxList.empty() && nums[maxList.back()] < nums[i]) {
                maxList.pop_back();
            }
            maxList.push_back(i);
        }
        while (right != nums.size() - 1) {
            result.push_back(nums[maxList.front()]);
            if (maxList.front() == left) {
                maxList.pop_front();
            }
            left++;
            right++;
            while (!maxList.empty() && nums[maxList.back()] < nums[right]) {
                maxList.pop_back();
            }
            maxList.push_back(right);
        }
        result.push_back(nums[maxList.front()]);
        return result;
    }
};