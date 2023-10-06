#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<vector<int>> cycle;
        vector<int> temp(8, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < 7; j++) {
                temp[j] = cells[j - 1] == cells[j + 1];
            }
            if (!cycle.empty() && cycle.front() == temp) {
                return cycle[(n - i - 1) % cycle.size()];
            }
            cycle.push_back(temp);
            cells = temp;
        }
        return cells;
    }
};