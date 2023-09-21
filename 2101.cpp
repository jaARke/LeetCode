#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void recHelper(int i, vector<vector<int>>& bombs, vector<vector<int>>& adjList, vector<bool>& seen, int& tempRes) {
        seen[i] = true;
        tempRes++;

        for (auto& x : adjList[i]) {
            if (!seen[x]) {
                recHelper(x, bombs, adjList, seen, tempRes);
            }
        }
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int res = 0;
        vector<vector<int>> adjList(bombs.size());

        for (int i = 0; i < bombs.size(); i++) {
            int curr = 1;
            for (int j = 0; j < bombs.size(); j++) {
                long long xDiff = pow((long long)(bombs[j][0] - bombs[i][0]), 2);
                long long yDiff = pow((long long)(bombs[j][1] - bombs[i][1]), 2);
                if (xDiff + yDiff <= pow((long long)bombs[i][2], 2)) {
                    adjList[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < bombs.size(); i++) {
            vector<bool> seen(bombs.size(), false);
            int tempRes = 0;
            recHelper(i, bombs, adjList, seen, tempRes);
            res = max(res, tempRes);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> bombs = {{2,1,3},{6,1,4}};
    cout << s.maximumDetonation(bombs) << endl;
    return 0;
}