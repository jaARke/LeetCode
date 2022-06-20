#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int result = INT32_MIN;
        while (i < j) {
            result = max(result, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> height = {2,3,4,5,18,17,6};
    cout << s.maxArea(height) << endl;
    return 0;
}