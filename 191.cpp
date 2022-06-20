#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

// Bit shifting = faster than pow() solution
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        if (n - pow(2, 31) >= 0) {
            count++;
            n -= (long)pow(2, 31);
        }
        for (int i = 30; i >= 0; i--) {
            if (n - (long)(1 << i) >= 0) {
                count++;
                n -= (long)(1 << i);
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.hammingWeight(92) << endl;
    return 0;
}