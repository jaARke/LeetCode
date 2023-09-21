#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (auto& x : asteroids) {
            while (!res.empty() && (x < 0 && res.back() > 0) && abs(x) > abs(res.back())) {
                res.pop_back();
            }
            if (res.empty() || !(x < 0 && res.back() > 0)) {
                res.push_back(x);
            }
            else if (abs(x) == abs(res.back())) {
                res.pop_back();
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> asteroids = {-2,-1,1,2};
    vector<int> res = s.asteroidCollision(asteroids);
    cout << "DONE" << endl;
    return 0;
}