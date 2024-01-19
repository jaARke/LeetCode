#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freqT(26, 0);
        int res = 0;

        for (char c : t) freqT[c - 'a']++;
        for (char c : s) freqT[c - 'a']--;

        for (int i = 0; i < 26; i++) {
            if (freqT[i] > 0) res += freqT[i];
        }

        return res;
    }
};