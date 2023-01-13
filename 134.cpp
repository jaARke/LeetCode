#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totSum = 0;
        int currSum = 0;
        int idx = -1;
        int flag = false;
        for (int i = 0; i < gas.size(); i++) {
            int currDiff = gas[i] - cost[i];
            currSum += currDiff;
            if (currSum < 0) {
                totSum += currSum;
                currSum = 0;
                flag = false;
            }
            else if (currDiff >= 0 && !flag) {
                idx = i;
                flag = true;
            }
        }
        return (currSum + totSum >= 0 ? idx : -1);
    }
};

int main() {
    Solution s;
    vector<int> gas = {6,1,4,3,5};
    vector<int> cost = {3,8,2,4,2};
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}