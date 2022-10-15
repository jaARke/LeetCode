#include <vector>
#include <queue>

using namespace std;

/*
Classic island graph problem. Upon discovering an island, run a DFS on it to count its area. Mark it as discovered by changing grid values from 1 to 0.
*/

class Solution {
private:
    void runDFS(vector<vector<int>>& grid, int i, int j, int& count) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        count++;
        runDFS(grid, i + 1, j, count);
        runDFS(grid, i - 1, j, count);
        runDFS(grid, i, j + 1, count);
        runDFS(grid, i, j - 1, count);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    runDFS(grid, i, j, count);
                    result = max(result, count);
                }
            }
        }
        return result;
    }
};