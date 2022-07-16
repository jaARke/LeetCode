#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> heights;
        vector<pair<int, int>> walls;
        vector<vector<int>> result;

        for (auto& x : buildings) { // Walls contains all start and end points of buildings
            walls.push_back(make_pair(x[0], -x[2]));
            walls.push_back(make_pair(x[1], x[2]));
        }
        sort(walls.begin(), walls.end());

        int currHeight = 0;
        for (auto& x : walls) {
            if (x.second < 0) { // Start of a building
                heights.insert(-x.second);
            }
            else {  // End of a building
                heights.erase(heights.find(x.second));
            }
            if (heights.empty()) {
                result.push_back({x.first, 0});
            }
            else if (currHeight != *heights.rbegin()) {
                currHeight = *heights.rbegin();
                result.push_back({x.first, currHeight});
            }
        }
        return result;
    }
};