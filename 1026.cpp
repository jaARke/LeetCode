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
    int runDFS(TreeNode* root, int big, int small) {
        if (!root) return 0;

        int ret = max(abs(root->val - big), abs(root->val - small));
        int newBig = max(root->val, big);
        int newSmall = min(root->val, small);

        if (big < 0 && small < 0) {
            ret = 0;
            newBig = root->val;
            newSmall = root->val;
        }

        int left = runDFS(root->left, newBig, newSmall);
        int right = runDFS(root->right, newBig, newSmall);

        return max(ret, max(left, right));
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return runDFS(root, -1, -1);
    }
};