#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (int i = 1; i < rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int rowIndex = 3;

    auto res = s.getRow(rowIndex);
    cout << "Done!" << endl;
    return 0;
}