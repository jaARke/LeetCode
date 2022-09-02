#include <queue>

using namespace std;

/*
Solved using memoized recursion -> run through every possibility while using a table that keeps track of how many options there are given xy coordinates and a number of remaining moves. For each recursive call,
we fill out part of the memo table for use on future calls to cut down runtime.  
*/

class Solution {
private:
    int m;
    int n;
    long long mod = 1e9 + 7;
    int recHelper(int row, int col, int moves, vector<vector<vector<int>>>& memo) {
        if (row >= m || col >= n || row < 0 || col < 0) {
            return 1;
        }
        if (moves == 0) {
            return 0;
        }
        if (memo[row][col][moves] != -1) {
            return memo[row][col][moves];
        }
        int up = recHelper(row + 1, col, moves - 1, memo);
        int down = recHelper(row - 1, col, moves - 1, memo);
        int left = recHelper(row, col - 1, moves - 1, memo);
        int right = recHelper(row, col + 1, moves - 1, memo);
        memo[row][col][moves] = ((up % mod) + (down % mod) + (left % mod) + (right % mod)) % mod;
        return memo[row][col][moves];
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return recHelper(startRow, startColumn, maxMove, memo);
    }
};

/*
Initial attempt using a BFS of the graph -> gives TLE. Need to reduce duplicate compute.
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        queue<long long> q1;
        queue<long long> q2;
        q1.push((long long)(startRow * 1e6) + startColumn);
        int count = 0;
        int result = 0;
        while (count <= maxMove) {
            while (!q1.empty()) {
                long long row = q1.front() / 1e6;
                long long col = q1.front() % (long long)1e6;
                q1.pop();
                if (row >= m || col >= n || row < 0 || col < 0) {
                    result++;
                    continue;
                }
                q2.push(((row + 1) * 1e6) + col);
                q2.push(((row - 1) * 1e6) + col);
                q2.push((row * 1e6) + (col + 1));
                q2.push((row * 1e6) + (col - 1));
            }
            count++;
            while (!q2.empty() && count <= maxMove) {
                long long row = q2.front() / 1e6;
                long long col = q2.front() % (long long)1e6;
                q2.pop();
                if (row >= m || col >= n || row < 0 || col < 0) {
                    result++;
                    continue;
                }
                q1.push(((row + 1) * 1e6) + col);
                q1.push(((row - 1) * 1e6) + col);
                q1.push((row * 1e6) + (col + 1));
                q1.push((row * 1e6) + (col - 1));
            }
            count++;
        }
        return result;
    }
};
*/