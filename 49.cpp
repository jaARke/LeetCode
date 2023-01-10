#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string>> res;
        for (const auto& s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            if (m.find(temp) != m.end()) {
                res[m[temp]].push_back(s);
            }
            else {
                res.push_back({s});
                m[temp] = res.size() - 1;
            }
        }
        return res;
    }
};