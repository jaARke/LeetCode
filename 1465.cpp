#include <vector>
#include <algorithm>

using namespace std;

/*
 * Find the biggest horizontal and vertical differences between consecutive cuts. Be sure to consider the pieces from
 * the edges of the cake.
 */

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxH = horizontalCuts.empty() ? h : max(horizontalCuts[0], h - horizontalCuts.back());
        int maxV = verticalCuts.empty() ? w : max(verticalCuts[0], w - verticalCuts.back());
        for (int i = 1; i < horizontalCuts.size(); i++) {
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); i++) {
            maxV = max(maxV, verticalCuts[i] - verticalCuts[i - 1]);
        }
        long long temp = (long long)maxV * maxH;
        return temp % (int)(1e9 + 7);
    }
};