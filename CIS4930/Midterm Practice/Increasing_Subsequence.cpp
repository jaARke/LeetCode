#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> LIS;
    int result = 0;
    for (int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        auto iter = lower_bound(LIS.begin(), LIS.end(), ni);
        if (iter == LIS.end()) {
            result++;
            LIS.push_back(ni);
        }
        else {
            *iter = ni;
        }
    }
    cout << result;
    return 0;
}