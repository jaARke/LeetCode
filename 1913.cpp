#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int h1 = INT32_MIN, h2 = INT32_MIN;
        int l1 = INT32_MAX, l2 = INT32_MAX;
        
        for (int x : nums) {
            if (x > h1) {
                h2 = h1;
                h1 = x;
            }
            else if (x > h2) {
                h2 = x;
            }
            if (x < l1) {
                l2 = l1;
                l1 = x;
            }
            else if (x < l2) {
                l2 = x;
            }
        }
        return (h1 * h2) - (l1 * l2);
    }
};