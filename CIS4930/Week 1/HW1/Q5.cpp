#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }
        int p1 = prices.size() - 1;
        int p2 = prices.size() - 2;
        int currMax = 0;
        while (p2 >= 0) {
            int diff = prices[p1] - prices[p2];
            if (diff <= 0) {
                p1 = p2;
                p2--;
            }
            else {
                currMax = max(currMax, diff);
                p2--;
            }
        }
        return currMax;
    }
};