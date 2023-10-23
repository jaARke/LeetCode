#include <bits/stdc++.h>

using namespace std;

int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> ans(box[0].size(), vector<char>(box.size()));

        for (int i = box.size() - 1; i >= 0; i--) {
            int open = -1;
            int ansI = box.size() - i - 1;
            for (int j = box[i].size() - 1; j >= 0; j--) {
                if (box[i][j] == '.') {
                    ans[j][ansI] = '.';
                    if (open == -1) open = j;
                }
                else if (box[i][j] == '*') {
                    ans[j][ansI] = '*';
                    open = -1;
                }
                else {
                    if (open != -1) {
                        ans[open][ansI] = '#';
                        ans[j][ansI] = '.';
                        open--;
                    }
                    else ans[j][ansI] = '#';
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<char>> box = {{'#','#','*','.','*','.'},
                                {'#','#','#','*','.','.'},
                                {'#','#','#','.','#','.'}};
    auto ans = s.rotateTheBox(box);
    cout << "Done!" << endl;
    return 0;
}