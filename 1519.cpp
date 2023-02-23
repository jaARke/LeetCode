#include <bits/stdc++.h>

using namespace std;

/*
The following solution is an optimization of the below. We observe that at each node, we need to count the frequency of that node's letter below the node itself. So, we keep track of the letter's frequency as it appears
when we arrive at the node. Then, we recursively traverse the tree and add to chars as we arrive at different letters. When going back up the recursive chain, the new value of the chars array will be compared to the
value when first arriving at a given node and the difference is our result.

DFS works well here because it ensures that a node is revisited exactly after all of its subtrees have been traversed, allowing us to obtain the correct result from the stated difference.
*/

class Solution {
private:
    void recHelper(vector<vector<int>>& adjList, vector<int>& res, vector<int>& chars, vector<bool>& seen, string& s, int curr) {
        seen[curr] = true;
        int prev = chars[s[curr] - 'a']++;
        for (int& x : adjList[curr]) {
            if (seen[x]) {continue;}
            recHelper(adjList, res, chars, seen, s, x);
        }
        res[curr] = chars[s[curr] - 'a'] - prev;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n, 0);
        vector<int> chars(26, 0);
        vector<bool> seen(n, false);
        vector<vector<int>> adjList(n);
        for (auto& x : edges) {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }
        recHelper(adjList, res, chars, seen, labels, 0);
        return res;
    }
};

/*
class Solution {
private:
    void recHelper(vector<vector<int>>& adjList, vector<int>& res, vector<int>& chars, vector<bool>& seen, string& s, int curr) {
        seen[curr] = true;
        for (int& x : adjList[curr]) {
            if (seen[x]) { continue; }
            vector<int> newChars(26, 0);
            recHelper(adjList, res, newChars, seen, s, x);
            for (int i = 0; i < 26; i++) {
                chars[i] += newChars[i];
            }
        }
        res[curr] = ++chars[s[curr] - 'a'];
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n, 0);
        vector<int> chars(26, 0);
        vector<bool> seen(n, false);
        vector<vector<int>> adjList(n);
        for (auto& x : edges) {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }
        recHelper(adjList, res, chars, seen, labels, 0);
        return res;
    }
};
*/

int main() {
    Solution s;
    int n = 7;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4},{4,5},{5,6}};
    string labels = "aaabaaa";
    auto res = s.countSubTrees(n, edges, labels);
    cout << "Done!" << endl;
    return 0;
}