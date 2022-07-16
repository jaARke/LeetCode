#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

long long calcSum(int idx, vector<long long>& segTree) {
    long long result = 0;
    while (idx > 0) {
        result += segTree[idx];
        idx -= idx & -idx;
    }
    return result;
}

void update(int idx, int newVal, int oldVal, int n, vector<long long>& segTree) {
    long long diff = newVal - oldVal;
    while (idx <= n) {
        segTree[idx] += diff;
        idx += idx & -idx;
    }
}

long long query(int l, int r, vector<long long>& segTree) {
    return calcSum(r, segTree) - calcSum(l - 1, segTree);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Count all of the divisors for numbers between 1 and 1000000
    vector<int> divs(1e6);
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            divs[j]++;
        }
    }

    // Read in parameters
    int n, m;
    cin >> n >> m;

    // Build the tree (Fenwick / BIT is used)
    // Set is used for tracking indices which will need to updated if they are within in a REPLACE request bounds (indices with value > 2)
    vector<long long> segTree(n + 1);
    vector<int> arr(n + 1);
    set<int> s;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s.insert(i);
        update(i, arr[i], 0, n, segTree);
    }

    // Process queries
    for (int i = 0; i < m; i++) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1) {
            // Find all indices with value greater than two and update them one-by-one
            auto iter = s.lower_bound(l);
            while (iter != s.end() && *iter <= r) {
                update(*iter, divs[arr[*iter]], arr[*iter], n, segTree);
                arr[*iter] = divs[arr[*iter]];
                if (arr[*iter] <= 2) {  // This index cannot be updated anymore -> don't consider it on future requests
                    auto nextIter = next(iter);
                    s.erase(iter);
                    iter = nextIter;
                }
                else {
                    iter++;
                }
            }
            // Unoptimized version of the above -> does not use a set to track significant indices (gives TLE)
            /*
            for (int j = l; j <= r; j++) {
                if (arr[j] != divs[arr[j]]) {
                    update(j, divs[arr[j]], arr[j], n, segTree);
                    arr[j] = divs[arr[j]];
                }
            }
            */
        }
        else {
            cout << query(l, r, segTree) << '\n';
        }
    }
    return 0;
}