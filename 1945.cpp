#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getLucky(string& s, int k) {
        // Convert step
        string temp = "";
        for (char c : s) {
            int cInt = (c - 'a') + 1;
            temp += to_string(cInt);
        }

        // Transform step(s)
        int res = 0;
        for (int i = 0; i < k; i++) {
            res = 0;
            for (char c : temp) {
                res += c - '0';
            }
            temp = to_string(res);
        }
        return res;
    }
};