using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == target) {
            return cloned;
        }
        if (original == nullptr) {
            return nullptr;
        }
        auto left = getTargetCopy(original->left, cloned->left, target);
        auto right = getTargetCopy(original->right, cloned->right, target);
        return (left == nullptr ? right : left);
    }
};