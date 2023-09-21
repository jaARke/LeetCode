#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    pair<double, double> recHelper(int a, int b, vector<vector<pair<double, double>>>& memo) {
        if (a < 0 && b >= 0) {
            return {1.0, 0.0};
        }
        if (a < 0 && b < 0) {
            return {0.0, 1.0};
        }
        if (b < 0) {
            return {0.0, 0.0};
        }

        if (memo[a][b].first != -1.0 && memo[a][b].second != -1.0) {
            return memo[a][b];
        }

        double aFirst = 0.0, both = 0.0;
        for (int i = 4; i > 0; i--) {
            auto temp = recHelper(a - i, b - (4 - i), memo);
            aFirst += temp.first;
            both += temp.second;
        }

        return memo[a][b] = {aFirst / 4.0, both / 4.0};
    }
public:
    double soupServings(int n) {
        if (n > 5000) return 1.0;
        int memoSize = ceil((double)n / (double)25);
        vector<vector<pair<double, double>>> memo(memoSize, vector<pair<double, double>>(memoSize, {-1.0, -1.0}));

        auto res = recHelper(memoSize - 1, memoSize - 1, memo);

        return res.first + ((0.5) * res.second);
    }
};

int main() {
    Solution s; 
    int n = 0;
    cout << s.soupServings(n) << endl;
    return 0;
}