#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    static bool cmp(vector<int>& lhs, vector<int>& rhs) {
        return lhs[1] > rhs[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int i = 0;
        int result = 0;
        while (truckSize > 0 && i < boxTypes.size()) {
            if (boxTypes[i][0] > truckSize) {
                result += (boxTypes[i][1] * truckSize);
                truckSize = 0;
            }
            else {
                result += (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
                i++;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> boxTypes = {{1,3},{5,5},{2,5},{4,2},{4,1},{3,1},{2,2},{1,3},{2,5},{3,2}};
    int truckSize = 35;
    cout << s.maximumUnits(boxTypes, truckSize) << endl;
    return 0;
}