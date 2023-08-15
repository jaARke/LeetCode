#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int res = 0;
    /*
    In the following DFS helper, we iterate through the child nodes of curr to find the second and first longest subtrees.
    With these, we try to overwrite the answer (meaning we would travel up from the leaf of one subtree, to curr, and then down to the leaf of the other).
    Then, we return the length of the largest subtree + 1. This is because if we choose not to cycle through curr (but instead some upper node), we can only take curr's largest subtree length with us, and not their sum.
        i.e. we couldn't go to curr from some higher node and then go to both of curr's subtrees--we have to pick the largest.
    */
    int recHelper(vector<vector<int>>& tree, int curr) {
        int first = 0;
        int second = 0;
        for (int& x : tree[curr]) {
            int temp = recHelper(tree, x);
            if (temp > first) {
                second = first;
                first = temp;
            }
            else if (temp > second) {
                second = temp;
            }
        }
        res = max(res, first + second + 1);
        return first + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> tree(parent.size());
        vector<int> roots = {0};
        // Construct the tree -> if a child has the same char as its parent, treat it as a potential root
        for (int i = 1; i < parent.size(); i++) {
            if (s[i] != s[parent[i]]) {
                tree[parent[i]].push_back(i);
            }
            else {
                roots.push_back(i);
            }
        }
        // For all potential roots, run the DFS helper
        for (int& x : roots) {
            recHelper(tree, x);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> parent = {-1,0,0,1,1,2};
    string str = "abacbe";
    cout << s.longestPath(parent, str) << endl;
    return 0;
}