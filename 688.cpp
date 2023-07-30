#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    double recHelper(int x, int y, int moves, vector<vector<vector<double>>>& log, const int n, const int k) {
        if (x >= n || y >= n || x < 0 || y < 0) {
            return 0.0;
        }
        if (moves == k) {
            return 1.0;
        }
        if (log[x][y][moves] != -1.0) {
            return log[x][y][moves];
        }
        double res = 0.0;
        res += recHelper(x - 1, y - 2, moves + 1, log, n, k);
        res += recHelper(x - 2, y - 1, moves + 1, log, n, k);
        res += recHelper(x - 1, y + 2, moves + 1, log, n, k);
        res += recHelper(x - 2, y + 1, moves + 1, log, n, k);
        res += recHelper(x + 1, y - 2, moves + 1, log, n, k);
        res += recHelper(x + 2, y - 1, moves + 1, log, n, k);
        res += recHelper(x + 1, y + 2, moves + 1, log, n, k);
        res += recHelper(x + 2, y + 1, moves + 1, log, n, k);
        log[x][y][moves] = res / 8.0;
        return res / 8.0;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> log(n, vector<vector<double>>(n, vector<double>(k, -1.0)));
        return recHelper(column, row, 0, log, n, k);
    }
};

int main() {
    Solution s;
    cout << s.knightProbability(3, 2, 0, 0) << endl;
    return 0;
}