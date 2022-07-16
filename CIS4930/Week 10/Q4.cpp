#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        // First, construct the 2D prefix sum matrix as described in class
        vector<vector<int>> preSum(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                preSum[i][j] = mat[i][j];
                if (i != 0 && j != 0) {
                    preSum[i][j] += preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1];
                }
                else if (j != 0) {
                    preSum[i][j] += preSum[i][j - 1];
                }
                else if (i != 0) {
                    preSum[i][j] += preSum[i - 1][j];
                }
            }
        }
        // Then, use the prefix sum matrix to compute the answer matrix
        vector<vector<int>> answer(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int rowLow = i - k - 1, rowHigh = i + k, colLow = j - k - 1, colHigh = j + k;
                if (rowHigh >= m) {
                    rowHigh = m - 1;
                }
                if (colHigh >= n) {
                    colHigh = n - 1;
                }
                answer[i][j] = preSum[rowHigh][colHigh];
                if (rowLow >= 0 && colLow >= 0) {
                    answer[i][j] += preSum[rowLow][colLow];
                }
                if (rowLow >= 0) {
                    answer[i][j] -= preSum[rowLow][colHigh];
                }
                if (colLow >= 0) {
                    answer[i][j] -= preSum[rowHigh][colLow];
                }
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    auto ans = s.matrixBlockSum(mat, 1);
    return 0;
}