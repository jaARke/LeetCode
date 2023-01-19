#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int i = 0;
        while (i < costs.size() && coins - costs[i] >= 0) {
            coins -= costs[i++];
        }
        return i;
    }
};