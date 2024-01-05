#include <bits/stdc++.h>

using namespace std;


class Solution {
private:
    vector<pair<int, int>> diff = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> res(img.size(), vector<int>(img[0].size(), 0));

        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[i].size(); j++) {
                int sum = img[i][j];
                int num = 1;

                for (auto& d : diff) {
                    if (i + d.first < img.size() && i + d.first >= 0 && j + d.second < img[i].size() && j + d.second >= 0) {
                        sum += img[i + d.first][j + d.second];
                        num++;
                    }
                }
                res[i][j] = sum / num;
            }
        }
        return res;
    }
};