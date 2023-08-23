#include <vector>
#include <unordered_map>
#include <iostream>

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
    vector<TreeNode*> recHelper(int n, int offset) {
        if (n == 0) {
            return {nullptr};
        }
        if (n == 1) {
            return {new TreeNode(offset + 1)};
        }

        vector<TreeNode*> res;
        for (int i = 0; i < n; i++) {
            vector<TreeNode*> left = recHelper(i, offset);
            vector<TreeNode*> right = recHelper(n - i - 1, i + offset + 1);

            for (auto& x : left) {
                for (auto& y : right) {
                    res.push_back(new TreeNode(i + offset + 1, x, y));
                }
            }
        }
        return res;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return recHelper(n, 0);
    }
};

int main() {
    Solution s;
    int n = 3;
    auto res = s.generateTrees(n);
    cout << "Done!" << endl;
    return 0;
}