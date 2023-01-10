#include <vector>
#include <iostream>

using namespace std;


/*
 * First solution using bottom-up dp. Kind of brute force and I'm not even sure of the logic behind it. Basically
 * just looked at patterns in diff lists until I came up with a solution.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> diffs;
        for (int i = 1; i < prices.size(); i++) {
            diffs.push_back(prices[i] - prices[i - 1]);
        }
        vector<int> dp(diffs.size() + 3);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 0;
        for (int i = 0; i < diffs.size(); i++) {
            // dp[j] = MAX(dp[j - 1] + diffs[i], dp[j - 3], dp[j - 2])
            // Where j = i + 3
            dp[i + 3] = max(dp[i + 2] + diffs[i], max(dp[i], dp[i + 1]));
        }
        return max(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};
 */

/*
 * The following solution is much more logical. We iterate through the list of prices and keep track of the maximum
 * profit that could be achieved by performing any of the three possible daily operations.
 * We treat the operations as states and note that you can either stay in a state or transfer from another state in
 * specific ways. For buy, you transfer from cooling down. For sell, you transfer from buying. For cooldown, you transfer
 * from sell.
 * For each price, we check if more profit can be made by transferring from another state on the specified day. If not,
 * we just keep the profit of that state on the previous day.
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sell = 0;
        int cool = 0;
        for (int price : prices) {
            int newBuy = max(buy, cool - price);
            int newSell = max(sell, buy + price);
            cool = max(cool, sell);
            buy = newBuy;
            sell = newSell;
        }
        return sell;
    }
};

int main() {
    Solution s;
    vector<int> prices = {2,1};
    cout << s.maxProfit(prices) << endl;
    return 0;
}