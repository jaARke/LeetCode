#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int recHelper(vector<vector<int>>& memo, int x, int y) {
        if (x == memo.size() - 1 && y == memo[0].size() - 1) return 1;
        if (x >= memo.size() || y >= memo[0].size()) return 0;
        if (memo[x][y] != -1) return memo[x][y];

        return memo[x][y] = recHelper(memo, x + 1, y) + recHelper(memo, x, y + 1);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return recHelper(memo, 0, 0);
    }
};