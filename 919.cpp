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

class CBTInserter {
private:
    TreeNode* root = nullptr;
    queue<TreeNode*> nextNodes;

    void levelOrderInit(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while (!q.empty()) {
            int nextI = 0;
            for (; i > 0; i--) {
                if (!q.front()->left || !q.front()->right) nextNodes.push(q.front());
                if (q.front()->left) {
                    nextI++;
                    q.push(q.front()->left);
                }
                if (q.front()->right) {
                    nextI++;
                    q.push(q.front()->right);
                }
                q.pop();
            }
            i = nextI;
        }
    }

public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        levelOrderInit(root);
    }
    
    int insert(int val) {
        int ret = nextNodes.front()->val;
        TreeNode* newNode = new TreeNode(val);
        nextNodes.push(newNode);

        if (!nextNodes.front()->left) {
            nextNodes.front()->left = newNode;
        }
        else {
            nextNodes.front()->right = newNode;
            nextNodes.pop();
        }
        return ret;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2), nullptr);
    CBTInserter s(root);
    s.insert(3);
    s.insert(4);
    auto res = s.get_root();
    cout << "Done!" << endl;
    return 0;
}
