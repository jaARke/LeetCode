#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0] = {1};
        for (int i = 1; i < numRows; i++) {
            vector<int> temp(res[i - 1].size() + 1, 1);
            for (int j = 1; j < res[i - 1].size(); j++) {
                temp[j] = res[i - 1][j] + res[i - 1][j - 1];
            }
            res[i] = temp;
        }
        return res;
    }
};

int main() {
    Solution s;
    int numRows = 5;
    auto res = s.generate(numRows);
    cout << "Done!" << endl;
    return 0;
}