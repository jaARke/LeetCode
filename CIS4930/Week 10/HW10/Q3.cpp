using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {    // Return root if it is null, p, or q
            return root;
        }
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr) {
            if (right != nullptr) {
                // This root is the LCA if both left and right are not null
                return root;
            }
            else {
                // Left is the LCA if it is not null and right is
                return left;
            }
        }
        // Otherwise, right is the LCA
        return right;
    }
};