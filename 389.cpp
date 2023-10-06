#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int tSum = t.back(), sSum = 0;
        for (int i = 0; i < s.length(); i++) {
            tSum += s[i];
            sSum += s[i];
        }
        return tSum - sSum;
    }   
};