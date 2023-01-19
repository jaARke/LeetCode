#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int res = 0;
    void recHelper(vector<vector<int>>& v, vector<bool>& hasApple, int& currPath, int currIdx) {
        if (hasApple[currIdx]) {
            res += currPath * 2;
        }
        for (int& x : v[currIdx]) {
            currPath++;
            recHelper(v, hasApple, currPath, x);
            currPath--;
        }
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> v(n);
        for (auto& x : edges) {
            v[x[0]].push_back(x[1]);
        }
        int currPath = 0;
        recHelper(v, hasApple, currPath, 0);
        return res;
    }
};

int main() {
    Solution s;
    int n = 7;
    vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool> hasApple = {false,false,true,false,true,true,false};
    cout << s.minTime(n, edges, hasApple) << endl;
    return 0;
}