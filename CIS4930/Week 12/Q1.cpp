#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void popTree(int curr, int left, int right, vector<int>& vals, vector<int>& segTree) {
    if (left == right) {
        segTree[curr] = vals[left];
        return;
    }
    int mid = (left + right) >> 1;
    popTree(curr << 1, left, mid, vals, segTree);
    popTree(curr << 1 | 1, mid + 1, right, vals, segTree);
    segTree[curr] = __gcd(segTree[curr << 1], segTree[curr << 1 | 1]);
}

void update(int curr, int idx, int val, int left, int right, vector<int>& segTree) {
    if (left == right) {
        segTree[curr] = val;
        return;
    }
    int mid = (left + right) >> 1;
    if (idx <= mid) {
        update(curr << 1, idx, val, left, mid, segTree);
    }
    else {
        update(curr << 1 | 1, idx, val, mid + 1, right, segTree);
    }
    segTree[curr] = __gcd(segTree[curr << 1], segTree[curr << 1 | 1]);
}

void query(int currNode, int currLeft, int currRight, int l, int r, int x, vector<int>& segTree, int& count) {
    if (count >= 2) {
        return;
    }
    if (segTree[currNode] % x == 0) {
        return;
    }
    if (currLeft == currRight) {
        count++;
        return;
    }

    int mid = (currRight + currLeft) >> 1;
    if (l <= mid) {
        query(currNode << 1, currLeft, mid, l, r, x, segTree, count);
    }
    if (r > mid) {
        query((currNode << 1) | 1, mid + 1, currRight, l, r, x, segTree, count);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    
    // Initialize the segment tree
    int h = ceil(log2(n));
    vector<int> vals(n + 1);
    vector<int> segTree(1 << (h + 1));
    for (int i = 1; i <= n; i++) {
        cin >> vals[i];
    }
    popTree(1, 1, n, vals, segTree);

    // Process queries
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {  // gcd query
            int l, r, x;
            cin >> l >> r >> x;
            int count = 0;
            query(1, 1, n, l, r, x, segTree, count);
            if (count < 2) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {  // Replace query
            int idx, val;
            cin >> idx >> val;
            update(1, idx, val, 1, n, segTree);
        }
    }
    return 0;
}