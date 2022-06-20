#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
 * General algorithm for finding intersections in interval lists (also called merging intervals or merging lists).
 * Go through each value in the lists with two separate pointers. At each step, find the maximum of starting points and
 * minimum of ending points. If low <= high, there is an intersection. After accounting, move the pointer forward in
 * the list that has the entry with the lower ending point.
 */

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int fIdx = 0, sIdx = 0;
        while (fIdx < firstList.size() && sIdx < secondList.size()) {
            int low = max(firstList[fIdx][0], secondList[sIdx][0]);
            int high = min(firstList[fIdx][1], secondList[sIdx][1]);
            if (low <= high) {
                res.push_back({low, high});
            }
            if (firstList[fIdx][1] < secondList[sIdx][1]) {
                fIdx++;
            }
            else {
                sIdx++;
            }
        }
        return res;
    }
};