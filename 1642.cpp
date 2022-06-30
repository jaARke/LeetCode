#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        for (int i = 0; i < heights.size() - 1; i++) {
            if (heights[i] >= heights[i + 1]) {
                continue;
            }
            int diff = heights[i + 1] - heights[i];
            bricks -= diff;
            pq.push(diff);
            while (bricks < 0 && ladders > 0) {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
            if (bricks < 0) {
                return i;
            }
        }
        return heights.size() - 1;
    }
};

/*
Recursive solution using DFS
class Solution {
private:
    int recHelper(int i, vector<int>& heights, int bricks, int ladders) {
        if (bricks < 0 || ladders < 0) {
            return i - 1;
        }
        if (i == heights.size() - 1) {
            return i;
        }
        if (heights[i + 1] <= heights[i]) {
            return recHelper(i + 1, heights, bricks, ladders);
        }
        else {
            return max(recHelper(i + 1, heights, bricks - (heights[i + 1] - heights[i]), ladders),
                       recHelper(i + 1, heights, bricks, ladders - 1));
        }
    }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        return recHelper(0, heights, bricks, ladders);
    }
};
 */