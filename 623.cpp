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

/*
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while (!q1.empty()) {
            if (--depth == 1) {
                while (!q1.empty()) {
                    auto v = q1.front();
                    q1.pop();
                    v->left = new TreeNode(val, v->left, nullptr);
                    v->right = new TreeNode(val, nullptr, v->right);
                }
                return root;
            }
            while (!q1.empty()) {
                auto v = q1.front();
                q1.pop();
                if (v->left) {
                    q2.push(v->left);
                }
                if (v->right) {
                    q2.push(v->right);
                }
            }
            if (--depth == 1) {
                while (!q2.empty()) {
                    auto v = q2.front();
                    q2.pop();
                    v->left = new TreeNode(val, v->left, nullptr);
                    v->right = new TreeNode(val, nullptr, v->right);
                }
                return root;
            }
            while (!q2.empty()) {
                auto v = q2.front();
                q2.pop();
                if (v->left) {
                    q1.push(v->left);
                }
                if (v->right) {
                    q1.push(v->right);
                }
            }
        }
        return nullptr;
    }
};
*/

class Solution {
private:
    void recHelper(TreeNode* root, int val, int depth, int curr) {
        if (!root) {
            return;
        }
        if (depth == curr) {
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
            return;
        }
        recHelper(root->left, val, depth, curr + 1);
        recHelper(root->right, val, depth, curr + 1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        recHelper(root, val, depth, 2);
        return root;
    }
};