#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int boardSize;
    void findRowCol(int next, int& row, int& col) {
        row = (next / boardSize - (next % boardSize == 0 ? 1 : 0));
        if (row % 2 == 0) {
            col = (next % boardSize) - 1;
            if (col < 0) {
                col = boardSize - 1;
            }
        }
        else {
            col = boardSize - (next % boardSize);
            if (col == boardSize) {
                col = 0;
            }
        }
        row = boardSize - row - 1;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        boardSize = board.size();
        queue<pair<int, int>> q;
        vector<bool> seen(pow(boardSize, 2) + 1, false); 
        q.push({1, 0});
        while (!q.empty()) {
            if (seen[q.front().first]) { 
                q.pop();
                continue; 
            }
            seen[q.front().first] = true;
            for (int i = 1; i <= 6; i++) {
                int next = q.front().first + i;
                if (next > pow(boardSize, 2)) { break; }
                int row, col;
                findRowCol(next, row, col);
                if (board[row][col] != -1) {
                    next = board[row][col];
                }
                if (next == pow(boardSize, 2)) {
                    return q.front().second + 1;
                }
                q.push({next, q.front().second + 1});
            }
            q.pop();
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> board = {{-1,-1,19,10,-1},{2,-1,-1,6,-1},{-1,17,-1,19,-1},{25,-1,20,-1,-1},{-1,-1,-1,-1,15}};
    cout << s.snakesAndLadders(board) << endl;
    return 0;
}