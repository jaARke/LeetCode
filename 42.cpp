#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
 * Use a stack to store height indices. Use these to compute distance between two 'pillars', which helps you find how
 * much water they can hold between them.
 * See here for general overview: https://liuzhenglaichn.gitbook.io/algorithm/monotonic-stack
 */

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int result = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!s.empty() && height[s.top()] < height[i]) {
                int top = s.top();
                s.pop();
                if (s.empty()) {
                    break;
                }
                result += (i - s.top() - 1) * (min(height[i], height[s.top()]) - height[top]);
            }
            s.push(i);
        }
        return result;
    }
};