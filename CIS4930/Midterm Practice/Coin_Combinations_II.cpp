#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    
    vector<int> denoms;
    for (int i = 0; i < n; i++) {
        int di;
        cin >> di;
        denoms.push_back(di);
    }
    
    // Make dp array and assign initial value:
    vector<long long> result(target + 1, 0);
    result[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = denoms[i]; j <= target; j++) {
            // Fill up the dp array by adding to previous values:
            result[j] += result[j - denoms[i]];
            // For correct formatting purposes:
            result[j] %= (int)1e9 + 7;
        }
    }
    cout << result[target];
    return 0;
}