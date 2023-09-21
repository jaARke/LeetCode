#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] = 1e4 * 1e4;
                }
                if (i > 0) {
                    mat[i][j] = min(mat[i][j], 1 + mat[i - 1][j]);
                }
                if (j > 0) {
                    mat[i][j] = min(mat[i][j], 1 + mat[i][j - 1]);
                }
            }
        }
        for (int i = mat.size() - 1; i >= 0; i--) {
            for (int j = mat[0].size() - 1; j >= 0; j--) {
                if (i < mat.size() - 1) {
                    mat[i][j] = min(mat[i][j], 1 + mat[i + 1][j]);
                }
                if (j < mat[0].size() - 1) {
                    mat[i][j] = min(mat[i][j], 1 + mat[i][j + 1]);
                }
            }
        }
        return mat;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    auto res = s.updateMatrix(mat);
    cout << "Done!" << endl;
    return 0;
}