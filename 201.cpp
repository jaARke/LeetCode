#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int leftBits = 0;
        int rightBits = 0;

        if (left == 0) {
            leftBits = 1;
        }
        else if (ceil(log2(left)) == log2(left)) {
            leftBits = ceil(log2(left)) + 1;
        }
        else {
            leftBits = ceil(log2(left));
        }

        if (right == 0) {
            rightBits = 1;
        }
        else if (ceil(log2(right)) == log2(right)) {
            rightBits = ceil(log2(right)) + 1;
        }
        else {
            rightBits = ceil(log2(right));
        }

        if (leftBits != rightBits) {
            return 0;
        }

        int res = left;
        while (left <= right) {
            res &= left;
            if (left == INT32_MAX) {
                break;
            }
            left++;
        }
        return res;
    }
};