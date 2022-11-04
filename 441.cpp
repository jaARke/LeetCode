#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0, j = n;
        while (i <= j) {
            int mid = (i + j) / 2;
            long long used = ((long long)mid * ((long long)mid + 1)) / 2;
            if (used == n) {
                return mid;
            }
            if (used > n) {
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }
        return j;
    }
};