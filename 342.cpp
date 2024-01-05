#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1) return false;
        while (n > 1) {
            if (n / 4 != ceil(n / 4.0)) return false;
            n /= 4;
        }
        return true;
    }
};