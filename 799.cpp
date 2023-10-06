#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(query_row + 1);
        tower[0] = {(double)poured};
        for (int i = 1; i <= query_row; i++) {
            tower[i] = vector<double>(i + 1);
            for (int j = 0; j <= i; j++) {
                double left = 0.0, right = 0.0;
                if (j - 1 >= 0 && tower[i - 1][j - 1] > 1) {
                    left = tower[i - 1][j - 1] - 1;
                }
                if (j <= i - 1 && tower[i - 1][j] > 1) {
                    right = tower[i - 1][j] - 1;
                }
                tower[i][j] = (left + right) / 2.0;
            }
        }
        return min(1.0, tower[query_row][query_glass]);
    }
};

int main() {
    Solution s;
    int poured = 25;
    int query_row = 6;
    int query_glass = 1;
    cout << s.champagneTower(poured, query_row, query_glass) << endl;
    return 0;
}