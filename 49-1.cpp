#include <bits/stdc++.h>

using namespace std;

int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string>> v;
        for (auto& s : strs) {
            string copy = s;
            sort(begin(s), end(s));
            
            if (m.find(s) == end(m)) {
                m[s] = v.size();
                v.push_back({copy});
            }
            else {
                v[m[s]].push_back(copy);
            }
        }
        return v;
    }
};