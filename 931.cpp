#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = matrix.size() - 2; i >= 0; i--) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int save = matrix[i][j];
                matrix[i][j] += matrix[i + 1][j];
                if (j - 1 >= 0) matrix[i][j] = min(matrix[i][j], save + matrix[i + 1][j - 1]);
                if (j < matrix[i].size() - 1) matrix[i][j] = min(matrix[i][j], save + matrix[i + 1][j + 1]);
            }
        }

        int res = INT32_MAX;
        for (int i = 0; i < matrix[0].size(); i++) res = min(res, matrix[0][i]);
        return res;
    }
};