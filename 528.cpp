#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> prefixSums;
public:
    Solution(vector<int>& w) {
        prefixSums = vector<int>(w.size(), 0);
        prefixSums[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            prefixSums[i] = prefixSums[i - 1] + w[i];
        }
    }
    
    int pickIndex() {
        int target = (rand() % prefixSums.back()) + 1;
        return lower_bound(begin(prefixSums), end(prefixSums), target) - begin(prefixSums);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */