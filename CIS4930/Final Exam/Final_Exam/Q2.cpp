#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void popTable(vector<vector<int>>& table) {
    for (int j = 1; (1 << j) <= (int)table.size(); j++) {
        for (int k = 0; (k + (1 << j)) - 1 < (int)table.size(); k++) {
            table[k][j] = min(table[k][j - 1], table[k + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int low, int high, vector<vector<int>>& table) {
    int temp = log2(high - low + 1);
    return min(table[low][temp], table[high - (1 << temp) + 1][temp]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Scenario #" << i + 1 << ":\n";
        int n, q;
        cin >> n >> q;
        vector<vector<int>> table(n + 1, vector<int>(log2(n) + 1, INT32_MAX));
        for (int j = 0; j < n; j++) {
            cin >> table[j][0];
        }
        popTable(table);
        for (int j = 0; j < q; j++) {
            int low, high;
            cin >> low >> high;
            if (low == high) {
                cout << table[low - 1][0] << '\n';
            }
            else {
                cout << query(low - 1, high - 1, table) << '\n';
            }
        }
    }
    return 0;
}
