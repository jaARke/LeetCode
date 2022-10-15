#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
private:
    bool check(vector<vector<char>>& board, vector<vector<bool>>& seen, string& word, int i, int j, int idx) {
        if (idx >= word.length()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[idx] != board[i][j] || seen[i][j]) {
            return false;
        }
        seen[i][j] = true;
        if (check(board, seen, word, i + 1, j, idx + 1) || check(board, seen, word, i - 1, j, idx + 1) ||
        check(board, seen, word, i, j + 1, idx + 1) || check(board, seen, word, i, j - 1, idx + 1)) {
            return true;
        }
        seen[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> seen(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && check(board, seen, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    Solution s;
    if (s.exist(board, "ABCESEEEFS")) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}