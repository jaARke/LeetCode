#include <string>

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
    void recHelper(TreeNode* root, string& res) {
        if (!root) {
            return;
        }
        res += to_string(root->val);
        res += '(';
        recHelper(root->left, res);
        if (res.back() != '(') {
            res += ')';
        }
        else {
            res.pop_back();
        }
        res += '(';
        recHelper(root->right, res);
        if (res.back() != '(') {
            res += ')';
        }
        else {
            res.pop_back();
        }
    }
public:
    string tree2str(TreeNode* root) {
        string res = "";
        recHelper(root, res);
        return res;
    }
};