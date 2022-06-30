#include <vector>
#include <iostream>

using namespace std;

/*
 * Incomplete -> current gives stack overflow from all the recursive calls
 */

class Solution {
private:
    bool recHelper(vector<int>& targ, vector<int>& curr) {
        if (targ == curr) {
            return true;
        }
        int sum = 0;
        for (auto& x : curr) {
            sum += x;
        }
        for (int i = 0; i < curr.size(); i++) {
            if (sum > targ[i]) {
                continue;
            }
            int temp = curr[i];
            curr[i] = sum;
            if (recHelper(targ, curr)) {
                return true;
            }
            curr[i] = temp;
        }
        return false;
    }
public:
    bool isPossible(vector<int>& target) {
        vector<int> curr(target.size(), 1);
        return recHelper(target, curr);
    }
};

int main() {
    Solution s;
    vector<int> target = {1,1000000000};
    if (s.isPossible(target)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}