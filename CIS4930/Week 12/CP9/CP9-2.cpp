#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void update(int idx, int val, int n, vector<long long>& segTree) {
    segTree[idx + n] = val;
    idx = (idx + n) / 2;
    for (int j = idx, count = 0; j > 0; j >>= 1, count++) {
        if (count % 2 != 0) {
            segTree[j] = (segTree[j << 1] ^ segTree[j << 1 | 1]);
        }
        else {
            segTree[j] = (segTree[j << 1] | segTree[j << 1 | 1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    n = 1 << n;
    int h = ceil(log2(n));

    vector<long long> segTree(1 << (h + 1));
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        update(i, a, n, segTree);
    }

    for (int i = 0; i < m; i++) {
        int p, b;
        cin >> p >> b;
        update(p - 1, b, n, segTree);
        cout << segTree[1] << '\n';
    }
    return 0;
}