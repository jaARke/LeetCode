#include <unordered_set>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
    /*
    Originally tried encoding positions as pairs with a custom hashing function, but it was slow and tedious. Pairs are instead stored as long long, with the x coordinate in the first 6 digits, and the y coordinate
    in the latter 6. 
    */
public:
    bool Helper(unordered_set<long long>& blockSet, vector<int>& source, vector<int>& target) {
        unordered_set<long long> visited;
        queue<long long> q;
        int limit = (pow(blockSet.size(), 2)) / 2;  // Maximum area that could be contained by the set of blocks
        q.push((long long)(source[0] * 1e6) + source[1]);

        while (!q.empty()) {
            // Check if the current position is valid
            if (visited.find(q.front()) != visited.end() || blockSet.find(q.front()) != blockSet.end()) {
                q.pop();
                continue;
            }
            // Extract the x and y coordinate positions and check if they match the target
            long long x = q.front() / 1e6;
            long long y = q.front() % (long long)1e6;
            if (x == target[0] && y == target[1]) {
                return true;
            }
            // Compute new coordinates if they are within the grid
            if (y + 1 < 1e6) {  
                q.push((x * 1e6) + (y + 1));
            }
            if (y - 1 > -1) {   
                q.push((x * 1e6) + (y - 1));
            }
            if (x + 1 < 1e6) { 
                q.push(((x + 1) * 1e6) + y);
            }
            if (x - 1 > -1) {   
                q.push(((x - 1) * 1e6) + y);
            }
            // Consider the current node as visited and remove it from the queue
            visited.insert(q.front());
            q.pop();
            // Run the BFS until the maximum area has been reached -> if you still have places to go, you can make it to the target
            if (visited.size() == limit) {
                return true;
            }
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.empty()) {
            return true;
        }
        unordered_set<long long> blockSet;
        for (int i = 0; i < blocked.size(); i++) {
            blockSet.insert((long long)(blocked[i][0] * 1e6) + blocked[i][1]);
        }
        if (Helper(blockSet, source, target) && Helper(blockSet, target, source)) {
            return true;
        }
        return false;
    }
};

// !!! USED FOR TESTING
int main() {
    Solution s;
    vector<vector<int>> blocked = {{691938, 300406}, {710196,624190}, {858790,609485}, {268029,225806}, {200010,188664}, {132599,612099}, {329444,633495}, {196657,757958}, {628509,883388}};
    vector<int> source = {655988,180910};
    vector<int> target = {267728,840949};
    if (s.isEscapePossible(blocked, source, target)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
}