#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;


long long query(int l, int r, int n, vector<long long>& segTree) {
    long long result = 0;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if (l % 2 == 1) {
            result += segTree[l++];
        }
        if (r % 2 == 0) {
            result += segTree[r--];
        }
    }
    return result;
}

void update(int idx, int val, int n, vector<long long>& segTree) {
    segTree[idx + n] = val;
    idx = (idx + n) / 2;
    for (int j = idx; j > 0; j >>= 1) {
        segTree[j] = segTree[j << 1] + segTree[j << 1 | 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Count all of the divisors for numbers between 1 and 1000000
    vector<short> divs(1e6);
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            divs[j]++;
        }
    }

    // Read in parameters
    int n, m;
    cin >> n >> m;
    int h = ceil(log2(n));  // Height of the tree

    // Build the tree (segment is used)
    vector<long long> segTree(1 << (h + 1));
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> segTree[n + i];
        s.insert(i);
    }
    for (int i = n - 1; i > 0; i--) {
        segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];
    }

    // Process queries
    for (int i = 0; i < m; i++) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1) {
            auto iter = s.lower_bound(l - 1);
            while (iter != s.end() && *iter < r) {
                update(*iter, divs[segTree[*iter + n]], n, segTree);
                if (segTree[*iter + n] < 3) {
                    auto nextIter = next(iter);
                    s.erase(iter);
                    iter = nextIter;
                }
                else {
                    iter++;
                }
            }
            /*
            for (int k = l - 1; k < r; k++) {
                update(k, divs[segTree[k + n]], n, segTree);
            }
            */
        }
        else {
            cout << query(l - 1, r - 1, n, segTree) << '\n';
        }
    }
    return 0;
}