#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        queue<TreeNode*> q1;
        q1.push(root);

        while (!q1.empty()) {
            queue<TreeNode*> q2;
            res.push_back(q1.front()->val);
            while (!q1.empty()) {
                if (q1.front()->right) {
                    q2.push(q1.front()->right);
                }
                if (q1.front()->left) {
                    q2.push(q1.front()->left);
                }
                q1.pop();
            }
            if (!q2.empty()) {
                res.push_back(q2.front()->val);
            }
            while (!q2.empty()) {
                if (q2.front()->right) {
                    q1.push(q2.front()->right);
                }
                if (q2.front()->left) {
                    q1.push(q2.front()->left);
                }
                q2.pop();
            }
        }
        return res;
    }
};