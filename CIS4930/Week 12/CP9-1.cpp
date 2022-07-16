#include <iostream>
#include <vector>

using namespace std;

long long calcSum(int idx, vector<long long>& segTree) {
    long long result = 0;
    while (idx > 0) {
        result += segTree[idx];
        idx -= idx & -idx;
    }
    return result;
}

void update(int idx, int diff, int n, vector<long long>& segTree) {
    while (idx <= n) {
        segTree[idx] += diff;
        idx += idx & -idx;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> segTree(n + 1, 0);
    for (int i = 0; i < q; i++) {
        char op;
        int idx, diff;
        cin >> op;
        if (op == '+') {
            cin >> idx >> diff;
            update(idx + 1, diff, n, segTree);
        }
        else {
            cin >> idx;
            cout << calcSum(idx, segTree) << '\n';
        }
    }
    return 0;
}