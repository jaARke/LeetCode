#include <unordered_map>
#include <set>
#include <vector>
#include <string>

using namespace std;

/*
 * This problem can also be solved by using binary search to find the first element in products that has the current prefix
 * of the searchWord. You then get the next two elements and add these to the result vector. The way I've done it is
 * a bit easier to understand, though. And uses some concepts that appear in similar questions.
 */

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string& searchWord) {
        unordered_map<string, set<string>> m;
        vector<vector<string>> res;
        for (auto& x : products) {
            for (int i = 1; i <= x.length(); i++) {
                m[x.substr(0, i)].insert(x);
            }
        }
        for (int i = 1; i <= searchWord.length(); i++) {
            vector<string> temp = {};
            string search = searchWord.substr(0, i);
            if (m[search].empty()) {
                res.push_back(temp);
                continue;
            }
            auto iter = m[search].begin();
            int count = 0;
            while (iter != m[search].end() && count < 3) {
                temp.push_back(*iter);
                iter++;
                count++;
            }
            res.push_back(temp);
        }
        return res;
    }
};