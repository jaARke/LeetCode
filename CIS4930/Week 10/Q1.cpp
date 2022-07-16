#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


void populateTable(vector<vector<int>>& table) {
    for (int i = 1; (1 << i) <= table.size(); i++) {
        for (int j = 0; (j + (1 << i)) - 1 < table.size(); j++) {
            table[j][i] = min(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int query(int low, int high, vector<vector<int>>& table) {  // Returns the minimum between low and high indices
    int temp = log2(high - low + 1);
    return min(table[low][temp], table[high - (1 << temp) + 1][temp]);
}

int main() {
    int n, k;
    cin >> n >> k;

    // Read in the array and populate the sparse table. Keep track of min and max value in the cases that k = 1 or k >= 3
    vector<vector<int>> table(n, vector<int>(log2(n) + 1, INT32_MAX)); // Got MLE using nxn dimensions -> maximum for each row is the log of the input amount
    int minNum = INT32_MAX, maxNum = INT32_MIN;
    for (int i = 0; i < n; i++) {
        cin >> table[i][0];
        minNum = min(minNum, table[i][0]);
        maxNum = max(maxNum, table[i][0]);
    }
    // The minimum of the array is the answer
    if (k == 1) {
        cout << minNum << endl;
    }
    // You can split the array so that one section only holds the maximum value, making that your answer
    else if (k >= 3) {
        cout << maxNum << endl;
    }
    // Compute RMQ for all possible splits (into two subsections)
    else {
        populateTable(table);
        int result = INT32_MIN;
        for (int i = 0; i < n - 1; i++) {
            result = max(result, max(query(0, i, table), query(i + 1, n - 1, table)));
        }
        cout << result << endl;
    }
    return 0;
}