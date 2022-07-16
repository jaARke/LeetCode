#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> prices(n + 1);   // prices[i].first = pi, prices[i].second = di
    for (int i = 1; i <= n; i++) {
        cin >> prices[i].first >> prices[i].second;
    }
    
}


/*
// Attempt at avoiding a segment tree (TLE & MLE, depending on whether memoization was used):
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> table(n + 1, vector<int>(7));
    vector<int> changes = {0, 1, 2, 3, 2, 1, 0};
    for (int i = 1; i <= n; i++) {
        int p, d;
        cin >> p >> d;
        for (int j = 0; j < 7; j++) {
            table[i][j] = (changes[j] * d) + p;
        }
    }

    int q;
    cin >> q;
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, INT32_MIN));
    for (int i = 0; i < q; i++) {
        int start, end;
        cin >> start >> end;
        int origStart = start;
        int maxProfit = INT32_MIN;
        int minPrice = table[start][0];
        int j = 1;
        if (start < end) {
            start++;
            while (start <= end) {
                if (memo[start][end] != INT32_MIN) {
                    maxProfit = max(maxProfit, memo[start][end]);
                    break;
                }
                maxProfit = max(maxProfit, table[start][j] - minPrice);
                minPrice = min(minPrice, table[start][j]);
                memo[origStart][start] = maxProfit;
                start++;
                if (++j > 6) {
                    j = 0;
                }
            }
        }
        else {
            start--;
            while (start >= end) {
                if (memo[start][end] != INT32_MIN) {
                    maxProfit = max(maxProfit, memo[start][end]);
                    break;
                }
                maxProfit = max(maxProfit, table[start][j] - minPrice);
                minPrice = min(minPrice, table[start][j]);
                memo[origStart][start] = maxProfit;
                start--;
                if (++j > 6) {
                    j = 0;
                }
            }
        }
        cout << (maxProfit > 0 ? maxProfit : 0) << "\n"; 
    }
    return 0;
}
*/
