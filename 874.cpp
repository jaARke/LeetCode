#include <bits/stdc++.h>

using namespace std;

int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_set<int>> m; // m[i] = a set of y coordinates with obstacles on the line x = i
        for (auto& x : obstacles) {
            m[x[0]].insert(x[1]);
        }

        pair<int, int> currPos(0, 0);
        pair<int, int> currDir(0, 1);
        int res = 0;
        for (int x : commands) {
            if (x == -2) {
                currDir.second = -currDir.second;
                swap(currDir.first, currDir.second);
            }
            else if (x == -1) {
                currDir.first = -currDir.first;
                swap(currDir.first, currDir.second);
            }
            else {
                for (int i = 0; i < x; i++) {
                    int nextX = currPos.first + currDir.first;
                    int nextY = currPos.second + currDir.second;
                    if (m[nextX].find(nextY) == m[nextX].end()) {
                        currPos.first = nextX;
                        currPos.second = nextY;
                        res = max(res, (int)pow(currPos.first, 2) + (int)pow(currPos.second, 2));
                    }
                    else break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> commands = {6,-1,-1,6};
    vector<vector<int>> obstacles = {};

    cout << s.robotSim(commands, obstacles) << endl;

    return 0;
}