#include <bits/stdc++.h>

using namespace std;

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