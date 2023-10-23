#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        int rCount = 0, dCount = 0;
        for (char c : senate) {
            q.push(c);
            if (c == 'R') rCount++;
            else dCount++;
        }

        while (rCount && dCount) {
            int rSkips = 0, dSkips = 0;
            
        }
    }
};