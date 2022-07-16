#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void populateTable(vector<vector<int>>& table) {    // Fills in the sparse table
    for (int i = 1; (1 << i) <= table.size(); i++) {
        for (int j = 0; (j + (1 << i)) - 1 < table.size(); j++) {
            table[j][i] = max(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int query(int low, int high, vector<vector<int>>& table) {  // Returns the maximum between low and high indices
    int temp = log2(high - low + 1);
    return max(table[low][temp], table[high - (1 << temp) + 1][temp]);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(log2(n) + 1, INT32_MIN));
    for (int i = 0; i < n; i++) {
        cin >> table[i][0];
    }
    populateTable(table);
    int count = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            count++;
            continue;
        }
        int localRes;
        if (a > b) {
            localRes = query(b, a - 1, table);
        }
        else {
            localRes = query(a - 1, b - 2, table);
        }

        if (localRes <= table[a - 1][0]) {
            count++;
        }
    }
    cout << count;
    return 0;
}