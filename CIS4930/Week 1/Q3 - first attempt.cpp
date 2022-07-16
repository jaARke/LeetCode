#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


long calcValue(int n, long targ) {
    vector<long> runningSum(n, 0);
    cin >> runningSum[0];
    // Base case: the cost of the first hotel is equal to lotto winnings
    if (runningSum[0] == targ) {
        return runningSum[0];
    }
    // Initialize result var based on the first value
    long result;
    if (runningSum[0] < targ) {
        result = runningSum[0];
    }
    else {
        result = 0;
    }
    for (int i = 1; i < n; i++) {
        long currVal;
        cin >> currVal;
        runningSum[i] = runningSum[i - 1] + currVal;
        // Case 1: the current sum is equal to lotto winnings
        if (runningSum[i] == targ) {
            return runningSum[i];
        }
        // Case 2: the current sum is less than the target
        if (runningSum[i] < targ) {
            result = runningSum[i];
        }
        // Case 3: the current sum is greater than the target -> subtract from the front until it's less than or equal to
        else {
            int j = 0;
            while (j < i && runningSum[i] - runningSum[j] > targ) {
                j++;
            }
            long diff = runningSum[i] - runningSum[j];
            // Sub-case 1: the difference is equal to target
            if (diff == targ) {
                return diff;
            }
            // Sub-case 2: the difference is greater than the current result -> overwrite it
            if (diff > result) {
                result = diff;
            }
            // Unspoken sub-case 3: the difference is less than the current result -> do nothing
        }
    }
    return result;
}


int main() {
    int n;
    long targ;
    cin >> n;
    cin >> targ;

    cout << calcValue(n, targ);
    return 0;
}
