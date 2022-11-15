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
    bool check(TreeNode* root, int target, int curr) {
        curr += root->val;
        if (!root->left && !root->right) {
            return curr == target;
        }
        if (!root->left) {
            return check(root->right, target, curr);
        }
        if (!root->right) {
            return check(root->left, target, curr);
        }
        return check(root->left, target, curr) || check(root->right, target, curr);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return root && check(root, targetSum, 0);
    }
};