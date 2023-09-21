#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool cmp(vector<int>& lhs, vector<int>& rhs) {
        return lhs[1] < rhs[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs), cmp);
        int end = pairs[0][1];
        int res = 1;
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > end) {
                end = pairs[i][1];
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> pairs = {{1,2},{2,3},{3,4}};
    cout << s.findLongestChain(pairs) << endl;
    return 0;
}