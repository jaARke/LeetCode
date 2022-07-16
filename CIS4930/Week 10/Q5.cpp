#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {
public:
    void populateTable(vector<vector<int>>& table) {    // Fills in the sparse table
        for (int i = 1; (1 << i) <= table.size(); i++) {
            for (int j = 0; (j + (1 << i)) - 1 < table.size(); j++) {
                table[j][i] = max(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    int query(int low, int high, vector<vector<int>>& table) {  // Returns the maximum between low and high indices
        int temp = log2(high - low + 1);
        return max(table[low][temp], table[high - (1 << temp) + 1][temp]);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<vector<int>> table(nums.size(), vector<int>(log2(nums.size()) + 1, INT32_MAX));
        for (int i = 0; i < nums.size(); i++) {
            table[i][0] = nums[i];
        }
        populateTable(table);
        vector<int> result;
        int i = 0, j = i + k - 1;
        while (j < nums.size()) {
            result.push_back(query(i, j, table));
            i++;
            j++;
        }
        return result;
    }
};