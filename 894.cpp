#include <vector>
#include <iostream>
#include <unordered_map>

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
    unordered_map<int, vector<TreeNode*>> log;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }
        if (n == 1) {
            return {new TreeNode()};
        }
        if (log[n].empty()) {
            vector<TreeNode*> res = {};

            for (int i = 1; i < n; i += 2) {
                vector<TreeNode*> left = allPossibleFBT(i);
                vector<TreeNode*> right = allPossibleFBT(n - i - 1);

                for (auto& x : left) {
                    for (auto& y : right) {
                        res.push_back(new TreeNode(0, x, y));
                    }
                }
            }
            log[n] = res;
            return res;
        }
        return log[n];
    }
};

int main() {
    Solution s;
    int n = 7;
    vector<TreeNode*> res = s.allPossibleFBT(n);
    cout << "Done!" << endl;

    return 0;
}