#include <bits/stdc++.h>

using namespace std;

/*
Key Insight: a 1 can always be added to the end of a monotone increasing string.

We iterate through the string and consider at each character:
If the current char is 1, we add to a variable that keep tracks of the number of 1s but do not change the answer.
If the current char is 0, we can either flip all previous 1s to 0s or flip the current to 1. In the former case, the new answer would be the number of 1s encountered. In the latter, the new
answer is simply 1 + current answer. We take the minimum of these two options.
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int num1s = 0, res = 0;
        for (auto& c : s) {
            if (c == '1') {
                num1s++;
            }
            else {
                res = min(res + 1, num1s);
            }
        }
        return res;
    }
};