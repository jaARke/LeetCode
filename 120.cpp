#include <vector>
#include <iostream>

using namespace std;

/*
 * The following is also a bottom-up DP approach, but simpler to understand than the one shown below it. The logic,
 * however, is the same. Put simply, each time we go up a row in the triangle, for each element in that row we are
 * taking the minimum of two possible paths to get to the bottom. Thus, we start from the bottom and combine paths for
 * each element as we work our way up, eventually taking the minimum of the two paths downward once we get to the apex.
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};

/*
 * This is bottom-up DP solution. We start with a vector containing the entries of the triangle's last row. Then,
 * for each row moving upwards we iterate the columns. For each column, we update the dp vector at that column's index.
 * To update, we add the element in triangle to the minimum of dp[j] and dp[j + 1]. These positions represent the two
 * paths that element is adjacent to; the two paths that can be taken to get to the bottom of the triangle from that
 * element.
 *
 * As we move up the triangle, the elements being updated in the dp vector shift more and more to the left. By the time
 * we reach the top, only the first element is updated, and this is the minimum path that can be taken to get down.
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = triangle.back();
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};
 */

/*
The following is a BFS solution that checks every possible path to find the minimum -> Gives TLE.
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        queue<vector<int>> q;
        int result = INT32_MAX;
        q.push({triangle[0][0], 0, 0}); // {total, row, column}
        while (!q.empty()) {
            int nRow = q.front()[1] + 1;
            int nCol = q.front()[2] + 1;
            if (nRow >= triangle.size()) {    // The elements in the queue are done
                result = min(result, q.front()[0]);
                q.pop();
                continue;
            }
            if (nCol < triangle[nRow].size()) {
                q.push({q.front()[0] + triangle[nRow][nCol], nRow, nCol});
            }
            q.push({q.front()[0] + triangle[nRow][q.front()[2]], nRow, q.front()[2]});
            q.pop();
        }
        return result;
    }
};
 */

int main() {
    Solution s;
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}