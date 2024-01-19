#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void dfs(TreeNode* root, vector<int>& res) {
        if (!root->left && !root->right) res.push_back(root->val);

        if (root->left) dfs(root->left, res);
        if (root->right) dfs(root->right, res);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2;
        dfs(root1, t1);
        dfs(root2, t2);

        if (t1.size() != t2.size()) return false;

        for (int i = 0; i < t1.size(); i++) {
            if (t1[i] != t2[i]) return false;
        }
        return true;
    }
};