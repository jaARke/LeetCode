#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix.size() - 1;
        while (j - i > 1) {
            int mid = (i + j) / 2;
            if (matrix[mid][0] > target) {
                j = mid - 1;
            }
            else if (matrix[mid][0] < target) {
                i = mid;
            }
            else {
                return true;
            }
        }
        int row = i;
        if (matrix[j][0] <= target) {
            row = j;
        }
        // Now we know that the element must be in row i
        i = 0, j = matrix[row].size() - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (matrix[row][mid] > target) {
                j = mid - 1;
            }
            else if (matrix[row][mid] < target) {
                i = mid + 1;
            }
            else {
                return true;
            }
        }
        return matrix[row][i] == target;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1},{3},{5}};
    int target = 3;
    if (s.searchMatrix(matrix, target)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}