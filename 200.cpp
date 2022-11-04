#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    void runBFS(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& seen) {
        queue<pair<int, int>> q;
        seen[i][j] = true;
        q.push(make_pair(i, j));
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x + 1 < grid.size() && grid[x + 1][y] == '1' && !seen[x + 1][y]) {
                seen[x + 1][y] = true;
                q.push(make_pair(x + 1, y));
            }
            if (x - 1 >= 0 && grid[x - 1][y] == '1' && !seen[x - 1][y]) {
                seen[x - 1][y] = true;
                q.push(make_pair(x - 1, y));
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] == '1' && !seen[x][y + 1]) {
                seen[x][y + 1] = true;
                q.push(make_pair(x, y + 1));
            }
            if (y - 1 >= 0 && grid[x][y - 1] == '1' && !seen[x][y - 1]) {
                seen[x][y - 1] = true;
                q.push(make_pair(x, y - 1));
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !seen[i][j]) {
                    runBFS(i, j, grid, seen);
                    count++;
                }
            }
        }
        return count;
    }
};
