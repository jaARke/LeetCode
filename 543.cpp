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
    int recHelper(TreeNode* root, int& res) {
        if (!root) {
            return 0;
        }
        int left = recHelper(root->left, res);
        int right = recHelper(root->right, res);
        res = max(res, left + right);
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        recHelper(root, res);
        return res;
    }
};