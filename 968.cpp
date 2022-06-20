#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * Use DFS to greedily place cameras. Starting from the bottom of the tree, if either of a node's children are not null
 * and not covered, you want to place a camera at that node. Upon placing the camera, you mark itself, its children, and
 * its parent as covered. You also have to account for the top of the tree, so if a node doesn't have a parent and isn't covered
 * you also place a camera there.
 */

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
    void recHelper(TreeNode* root, TreeNode* parent, int& count, unordered_set<TreeNode*>& done) {
        if (!root) {
            return;
        }
        recHelper(root->left, root, count, done);
        recHelper(root->right, root, count, done);
        if ((!parent && done.find(root) == done.end()) || done.find(root->left) == done.end() || done.find(root->right) == done.end()) {
            count++;
            done.insert(root);
            done.insert(parent);
            done.insert(root->left);
            done.insert(root->right);
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        int count = 0;
        unordered_set<TreeNode*> done;
        done.insert(nullptr);   // To make sure cameras are not placed for null children
        recHelper(root, nullptr, count, done);
        return count;
    }
};

int main() {
    auto* t = new TreeNode(0, new TreeNode(0, new TreeNode(0, new TreeNode(0, nullptr,
                                                                           new TreeNode(0)), nullptr), nullptr), nullptr);
    Solution s;
    cout << s.minCameraCover(t) << endl;
    return 0;
}