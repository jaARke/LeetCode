#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * We keep a monotonically decreasing stack -> each iteration, we check if the element's height is less than that of the
 * element currently on top of the stack. If it is, we pop off until we get to an element whose height is not less than the
 * current element.
 * Each time we pop off, we save the height of the stack's top element. We then compute width as the
 * distance between the current index and the element in front of the next element on the stack. This is because we know that
 * all elements before the one we're popping and after the next one are at least as tall as the one we're popping, so
 * they should all be included in the width. With these values for width and height, we check if we can overwrite our current
 * answer.
 * This explains somewhat better: https://abhinandandubey.github.io/posts/2019/12/15/Largest-Rectangle-In-Histogram.html
 * And this is excellent for monotonic stacks in general: https://liuzhenglaichn.gitbook.io/algorithm/monotonic-stack
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int leftIdx = s.empty() ? -1 : s.top(); // If the stack is empty, the width should be i - 0, so leftIdx = -1.
                result = max(result, (i - leftIdx - 1) * height);
            }
            s.push(i);
        }
        while (!s.empty()) {    // Empty the stack at the end
            int height = heights[s.top()];
            s.pop();
            int leftIdx = s.empty() ? -1 : s.top();
            result = max(result, ((int)heights.size() - leftIdx - 1) * height);
        }
        return result;
    }
};


int main() {
    Solution s;
    vector<int> heights = {1,2,3,4,5};
    cout << s.largestRectangleArea(heights);
    return 0;
}