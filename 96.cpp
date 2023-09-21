#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> memo;

public:
    int numTrees(int n) {
        if (n == 1 || n == 0) {
            return 1;
        }
        if (memo[n] == 0) {
            for (int i = 0; i < n; i++) {
                int left = numTrees(i);
                int right = numTrees(n - i - 1);

                memo[n] += left * right;
            }
        }
        return memo[n];
    }
};