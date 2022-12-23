#include <queue>

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
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> even;
        queue<TreeNode*> odd;
        int prev = 0;
        even.push(root);
        while (!even.empty()) {
            prev = 0;
            while (!even.empty()) {
                auto front = even.front();
                even.pop();
                if (front->val <= prev || front->val % 2 != 1) {
                    return false;
                }
                prev = front->val;
                if (front->left) {
                    odd.push(front->left);
                }
                if (front->right) {
                    odd.push(front->right);
                }
            }
            prev = INT32_MAX;
            while (!odd.empty()) {
                auto front = odd.front();
                odd.pop();
                if (front->val >= prev || front->val % 2 != 0) {
                    return false;
                }
                prev = front->val;
                if (front->left) {
                    even.push(front->left);
                }
                if (front->right) {
                    even.push(front->right);
                }
            }
        }
        return true;
    }
};