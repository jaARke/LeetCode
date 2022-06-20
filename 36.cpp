#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(10, vector<bool>(10, false));
        vector<vector<bool>> cols(10, vector<bool>(10, false));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                vector<bool> sq(10, false);
                for (int k = i * 3; k < (i * 3) + 3; k++) {
                    for (int l = j * 3; l < (j * 3) + 3; l++) {
                        if (board[k][l] == '.') {
                            continue;
                        }
                        int curr = board[k][l] - '0';
                        if (curr > 9 || curr < 0 || sq[curr] || rows[k][curr] || cols[l][curr]) {
                            return false;
                        }
                        sq[curr] = true;
                        rows[k][curr] = true;
                        cols[l][curr] = true;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> nums = {{'8','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};
    Solution s;
    if (s.isValidSudoku(nums)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}