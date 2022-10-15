from ast import List

class Solution:
    def rotate(self, matrix) -> None:
        for i in range(len(matrix)):
            for j in range(i, len(matrix)):
                matrix[i][j], matrix[j][i] = matrix [j][i], matrix[i][j]
        for i in range(len(matrix)):
            matrix[i].reverse()

matrix = [[1,2,3],[4,5,6],[7,8,9]]
s = Solution
s.rotate(s, matrix=matrix)
print("Done!")
        