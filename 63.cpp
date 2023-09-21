#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int recHelper(int x, int y, vector<vector<int>>& obstacleGrid, vector<vector<int>>& paths) {
        if (x >= obstacleGrid.size() || y >= obstacleGrid[0].size() || obstacleGrid[x][y] == 1) {    // Out of bounds or obstacle
            return 0;
        }
        if (x == obstacleGrid.size() - 1 && y == obstacleGrid[0].size() - 1) {  // Reached the end
            return 1;
        }
        if (paths[x][y] > -1) {
            return paths[x][y];
        }

        int right = recHelper(x + 1, y, obstacleGrid, paths);
        int down = recHelper(x, y + 1, obstacleGrid, paths);

        return paths[x][y] = right + down;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> paths(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));

        return recHelper(0, 0, obstacleGrid, paths);
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << s.uniquePathsWithObstacles(grid) << endl;
    return 0;
}