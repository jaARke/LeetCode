#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size(), 0);
        sort(begin(potions), end(potions));

        int minSpell = INT32_MIN;

        for (int i = spells.size() - 1; i >= 0; i--) {
            if (spells[i] <= minSpell) continue;
            long long potStrength = ceil((double) success / (double) spells[i]);

            auto iter = lower_bound(begin(potions), end(potions), potStrength);

            res[i] = end(potions) - iter;

            if (res[i] == 0) minSpell = max(minSpell, spells[i]);
        }
        return res;
    }
};