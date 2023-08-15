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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty() && q.front()->left) {
            count++;
            TreeNode* front = q.front();
            q.pop();
            q.push(front->left);
            if (!front->right) {
                break;
            }
            q.push(front->right);
        }
        return count + q.size();
    }
};
*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        int leftCnt = 0, rightCnt = 0;
        TreeNode* iter = root;
        while (iter) {
            iter = iter->left;
            leftCnt++;
        }
        iter = root;
        while (iter) {
            iter = iter->right;
            rightCnt++;
        }
        if (leftCnt == rightCnt) {
            return (1 << leftCnt) - 1; 
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


