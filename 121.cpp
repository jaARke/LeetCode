#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = INT32_MIN;
        int currMin = INT32_MAX;
        for (int& price : prices) {
            currMin = min(currMin, price);
            result = max(result, price - currMin);
        }
        return result;
    }
};