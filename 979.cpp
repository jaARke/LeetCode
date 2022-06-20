#include <iostream>

using namespace std;

/*
 * We run a DFS on the tree. For each node, we compute the excess or deficit of that node's value from the
 * desired value of 1. A positive value indicates an excess, a negative value indicates a deficit. We combine the excesses
 * and deficits from the left and right branches of the tree, while adding: (value of the current node - 1), which represents
 * that node's excess or deficit value. We return this combined value from the recursive loop to be used in the rest of the call
 * chain. Meanwhile, our result (count) is updated by the absolute value sum of the left and right tree values. This is
 * because we know we will have to move the excess number of coins through the node to get to higher parts of the tree.
 * We also know that we will have to move the deficit number of coins through the node to get to lower parts of the tree.
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
    int recHelper(TreeNode* root, TreeNode* parent, int& count) {
        if (!root) {
            return 0;
        }
        int l = recHelper(root->left, root, count);
        int r = recHelper(root->right, root, count);
        count += abs(l) + abs(r);
        return root->val + l + r - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        int count = 0;
        recHelper(root, nullptr, count);
        return count;
    }
};