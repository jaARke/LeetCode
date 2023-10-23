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
    unordered_set<int> seen;

    bool deleteDefect(TreeNode* root) {
        seen.insert(root->val);

        if (root->right) {
            if (seen.find(root->right->val) != end(seen)) return true;
            if (deleteDefect(root->right)) {
                root->right = nullptr;
                return false;
            }
        }
        if (root->left) {
            if (deleteDefect(root->left)) {
                root->left = nullptr;
                return false;
            }
        }
        return false;
    }

public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        deleteDefect(root);
        return root;
    }
};