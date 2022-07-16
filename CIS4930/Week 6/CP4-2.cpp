#include <iostream>
#include <vector>
#include <set>

using namespace std;


bool check(vector<int>& denoms) {
    int target = denoms[denoms.size() - 1] + denoms[denoms.size() - 2];
    vector<int> dp(target, INT32_MAX);
    vector<int> greedy(target);
    dp[0] = 0;
    dp[1] = 1;
    greedy[0] = 0;
    greedy[1] = 1;

    for (int i = 2; i < target; i++) {
        for (int j : denoms) {
            if (j <= i) {
                dp[i] = min(dp[i], dp[i - j] + 1);
                greedy[i] = greedy[i - j] + 1;  // Overwrite with each higher coin value
            }
        }
        if (greedy[i] > dp[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> denoms;
    for (int i = 0; i < n; i++) {
        int di;
        cin >> di;
        denoms.push_back(di);
    }

    if (check(denoms)) {
        cout << "canonical" << endl;
    }
    else {
        cout << "non-canonical" << endl;
    }
    return 0;
}