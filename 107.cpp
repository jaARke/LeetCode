#include <vector>
#include <queue>
#include <algorithm>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        int curr = 1;
        int next = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> levelRes;
            while (curr-- > 0) {
                TreeNode* u = q.front();
                levelRes.push_back(u->val);
                if (u->left) {
                    q.push(u->left);
                    next++;
                }
                if (u->right) {
                    q.push(u->right);
                    next++;
                }
                q.pop();
            }
            res.push_back(levelRes);
            curr = next;
            next = 0;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};