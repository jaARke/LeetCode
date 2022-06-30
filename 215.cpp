#include <vector>
#include <queue>

using namespace std;

/*
 * Most complicated way of solving this problem in good time is using a min heap to keep track of the k greatest
 * elements. If the current element is greater than the top of the min heap, pop the heap and push on that element.
 * This ensures we always have a heap of the k greatest.
 * At the end, we just return the top of the heap.
 *
 * Easiest way to solve is to use nth_element STL function.
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return *(nums.end() - k);
    }
};

/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto& x : nums) {
            if (pq.size() < k) {
                pq.push(x);
            }
            else if (pq.top() < x) {
                pq.pop();
                pq.push(x);
            }
        }
        return pq.top();
    }
};
 */