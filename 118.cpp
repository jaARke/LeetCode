#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++) {
            int j = 0;
            while (j < i + 1) {
                if (j - 1 < 0 || i - 1 < 0 || j >= i) {
                    res[i].push_back(1);
                }
                else {
                    res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
                j++;
            }
        }
        return res;
    }
};