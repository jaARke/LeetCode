#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> w1;
        set<int> w2;
        set<int> blacklist;
        for (auto& x : matches) {
            if (w1.find(x[0]) == w1.end() && w2.find(x[0]) == w2.end() && blacklist.find(x[0]) == blacklist.end()) {    // We have a new winner -> add it to w1
                w1.insert(x[0]);
            }
            if (w1.find(x[1]) != w1.end()) {    // The loser is in w1 -> move it to w2
                w1.erase(x[1]);
                w2.insert(x[1]);
            }
            else if (w2.find(x[1]) != w2.end()) {   // The loser is in w2 -> move it to blacklist
                w2.erase(x[1]);
                blacklist.insert(x[1]);
            }
            else if (blacklist.find(x[1]) == blacklist.end()) { // The loser is not in w1, w2, or blacklist -> add it to w2
                w2.insert(x[1]);
            }
        }
        return {vector<int>(w1.begin(), w1.end()), vector<int>(w2.begin(), w2.end())};
    }
};
*/

// OR

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> v(1e5 + 1, -1);
        for (auto& x : matches) {
            if (v[x[0]] == -1) {
                v[x[0]] = 0;
            }
            if (v[x[1]] == -1) {
                v[x[1]] = 1;
            }
            else {
                v[x[1]]++;
            }
        }
        vector<vector<int>> res = {vector<int>(), vector<int>()};
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == 0) {
                res[0].push_back(i);
            }
            if (v[i] == 1) {
                res[1].push_back(i);
            }
        }
        return res;
    }
};