#include <vector>
#include <algorithm>

using namespace std;

/*
 * Sort the input vector in decreasing order of height. In the case of a tie, increasing order of position. We then
 * iterate through each entry and insert into the result queue at the index position specified by x[1].
 */

class Solution {
private:
    static bool cmp(vector<int>& lhs, vector<int>& rhs) {
        if (lhs[0] == rhs[0]) {
            return lhs[1] < rhs[1];
        }
        return lhs[0] > rhs[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (auto& x : people) {
            res.insert(res.begin() + x[1], x);
        }
        return res;
    }
};