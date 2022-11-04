#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<bool>> seen(matrix.size(), vector<bool>(matrix[0].size(), false));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0 && !seen[i][j]) {
                    seen[i][j] = true;
                    for (int k = 0; k < matrix.size(); k++) {
                        if (!seen[k][j]) {
                            seen[k][j] = matrix[k][j] != 0;
                        }
                        matrix[k][j] = 0;
                    }
                    for (int k = 0; k < matrix[0].size(); k++) {
                        if (!seen[i][k]) {
                            seen[i][k] = matrix[i][k] != 0;
                        }
                        matrix[i][k] = 0;
                    }
                }
            }
        }
    }
};