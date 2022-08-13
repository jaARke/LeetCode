#include <algorithm>

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
    bool recHelper(TreeNode* root, long long upperBnd, long long lowerBnd) {
        if (!root) {
            return true;
        }
        if (root->val >= upperBnd || root->val <= lowerBnd) {
            return false;
        }
        return recHelper(root->left, root->val, lowerBnd) && recHelper(root->right, upperBnd, root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return recHelper(root, INT64_MAX, INT64_MIN);
    }
};