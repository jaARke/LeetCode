#include <bits/stdc++.h>

using namespace std;

/*
This solution times out, but it's a good reference for constructing a Fenwick tree and using it to compute minimums.
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<vector<int>> v(arr.size(), vector<int>(log2(arr.size()) + 1));
        for (int i = 0; i < arr.size(); i++) {
            v[i][0] = arr[i];
        }
        for (int j = 1; j < v[0].size(); j++) {
            for (int i = 0; i < v.size(); i++) {
                if (i + (1 << j) - 1 < v.size()) {
                    v[i][j] = min(v[i][j - 1], v[i + (1 << (j - 1))][j - 1]);
                }
            }
        }
        // Compute the answer from the Fenwick tree
        long long res = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i; j < arr.size(); j++) {
                int temp = log2(j - i + 1);
                res += min(v[i][temp], v[j - (1 << temp) + 1][temp]);
            }
        }
        return res % 1000000007;
    }
};

int main() {
    Solution s;
    vector<int> v = {11,81,94,43,3};
    cout << s.sumSubarrayMins(v) << endl;
    return 0;
}