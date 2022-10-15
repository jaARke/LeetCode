#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (seen.find(n) == seen.end() && n != 1) {
            seen.insert(n);
            int temp = 0;
            for (auto& x : to_string(n)) {
                temp += pow(x - '0', 2);
            }
            n = temp;
        }
        return n == 1;
    }
};