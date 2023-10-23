#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int runBFS(int i, vector<int>& leftChild, vector<int>& rightChild) {
        queue<int> q;
        vector<bool> seen(leftChild.size(), false);
        q.push(i);
        int res = 0;
        while(!q.empty()) {
            int j = q.front();
            seen[j] = true;
            res++;
            q.pop();

            if (leftChild[j] != -1) {
                if (seen[leftChild[j]]) res++;
                else q.push(leftChild[j]);
            }
            if (rightChild[j] != -1) {
                if (seen[rightChild[j]]) res++;
                else q.push(rightChild[j]);
            }
        }
        return res;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> seen(n, false);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) seen[leftChild[i]] = true;
            if (rightChild[i] != -1) seen[rightChild[i]] = true;
        }

        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                return runBFS(i, leftChild, rightChild) == n;
            }
        }
        return false;
    }
};