#include <vector>
#include <iostream>

using namespace std;

/*
 * Very tedious problem; first solution is essentially an exercise in iteration. We swap groups of 4 elements at a time
 * using some clever math.
 * A much more elegant way of solving this problem is by transposing the matrix (reversing on a diagonal axis), and
 * then reversing each row. This solution is shown second, and is described in detail here: https://leetcode.com/problems/rotate-image/solution/
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sideLength = matrix.size();
        while (sideLength > 1) {
            int origin = (matrix.size() - sideLength) / 2;  // Stores the starting index for swapping
            int maxIdx = matrix.size() - origin - 1;    // Stores the max index for this iteration
            for (int i = 0; i < sideLength - 1; i++) {
                int next = matrix[origin][origin + i];
                int p1 = origin, p2 = origin + i;
                // Add to p2
                p2 += (sideLength - 1);
                if (p2 > maxIdx) {
                    p1 += (p2 - maxIdx);
                    p2 = maxIdx;
                }
                for (int j = 0; j < 3; j++) {
                    swap(next, matrix[p1][p2]);
                    if (j == 0) {   // Add to p1
                        p1 += (sideLength - 1);
                        if (p1 > maxIdx) {
                            p2 -= (p1 - maxIdx);
                            p1 = maxIdx;
                        }
                    }
                    else if (j == 1) {  // Subtract from p2
                        p2 -= (sideLength - 1);
                        if (p2 < origin) {
                            p1 -= (origin - p2);
                            p2 = origin;
                        }
                    }
                    else {  // Subtract from p1
                        p1 -= (sideLength - 1);
                        if (p1 < origin) {
                            p2 += (origin - p1);
                            p1 = origin;
                        }
                    }
                }
                swap(next, matrix[p1][p2]); // Final swap
            }
            sideLength -= 2;
        }
    }
};


/*
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i; j < matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (auto& i : matrix) {
            reverse(i.begin(), i.end());
        }
    }
};
*/
int main() {
    Solution s;
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    s.rotate(matrix);
    cout << "Done!" << endl;
    return 0;
}