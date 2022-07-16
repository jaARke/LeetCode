#include <algorithm>
#include <vector>

using namespace std;
/*
- starts at any element in the first row
- chooses element in the next row that is either directly below, or diagonal left/right
- this is (i, j) -> (i + 1, j), (i + 1, j - 1), (i+1, j+1) (down, diag-left, diag-right)

- think about the last row:
- for the first element in the row, I can only reach this from above or diag right
- for the last element in the row, I can only reach this from above or diag left
- for every thing else, I can reach from three positions

- then dp(i, j) is the min sum falling path to this entry a(i, j) in the matrix

- base cases? for the first row i = 0, we have dp(0, j) = a(0, j)
- then we go row by row, and for each row, check each entry, store the best choice into dp(i, j)
- at the end, we'll check which entry in dp has the min path sum

*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size(); // rows
        int m = matrix[0].size(); // columns
        vector<vector<int>> dp(n, vector<int>(m + 1));
        
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j]; // 1st row
        }
        
        for (int i = 1; i < n; i++) { // each row
            for (int j = 0; j < m; j++) { // each entry in the row
                
                
                if (j == 0) { // leftmost entry
                    dp[i][j] = min(dp[i - 1][j] + matrix[i][j], dp[i - 1][j + 1] + matrix[i][j]);
                }
                
                else if (j == m - 1) { // rightmost entry
                    dp[i][j] = min(dp[i - 1][j] + matrix[i][j], dp[i - 1][j - 1] + matrix[i][j]);
                }
                
                else {
                    dp[i][j] = min({dp[i - 1][j - 1] + matrix[i][j], dp[i - 1][j] + matrix[i][j], dp[i - 1][j + 1] + matrix[i][j]});
                }
                
            }
        
        }
        
        // min path sum will be one of the entries in the last row; pass it along
        for (int i = 1; i < m; i++) {
            dp[n - 1][i] = min(dp[n - 1][i], dp[n - 1][i - 1]);
        }
        
        return dp[n - 1][m - 1];
    }
        
};