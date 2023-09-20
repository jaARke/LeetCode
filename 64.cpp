#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            if (i != 0) grid[i][0] += grid[i - 1][0];
            for (int j = 1; j < grid[i].size(); j++) {
                if (i == 0) grid[i][j] += grid[i][j - 1];
                else grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << s.minPathSum(grid) << endl;
    return 0;
}