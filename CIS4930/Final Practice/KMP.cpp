#include <iostream>
#include <vector>

using namespace std;

void constructPrefix(vector<int>& prefix, string& p) {
    for (int i = 1; i < p.length(); i++) {
        int j = prefix[i - 1];
        while (j > 0 && p[i] != p[j]) {
            j = prefix[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        prefix[i] = j;
    }
}

void KMP(string& s, string& p, vector<int>& prefix) {
    int sIdx = 0, pIdx = 0;
    while (sIdx < s.length()) {
        if (s[sIdx] == p[pIdx]) {
            if (pIdx == p.length() - 1) {
                // Pattern found starting at (sIdx - pIdx)
                pIdx = prefix.back();
                sIdx++;
            }
            else {
                sIdx++;
                pIdx++;
            }
        }
        else {
            if (pIdx > 0) {
                pIdx = prefix[pIdx - 1];
            }
            else {
                sIdx++;
            }
        }
    }
}