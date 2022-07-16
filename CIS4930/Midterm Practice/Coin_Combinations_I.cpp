#include <iostream>
#include <vector>

using namespace std;

/*
Similar to Coin Combinations II, except in this one you want to add ~the sum at result[i - denom] for all values of denom~ to result[i] in one iteration.
In the other one, you were cycling through the denoms in the outer loop. In this one, you do the opposite.
*/

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> denoms;
    for (int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        denoms.push_back(ni);
    }

    vector<long long> result(target + 1, 0);
    result[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < denoms.size(); j++) {
            if (i - denoms[j] >= 0) {
                result[i] += result[i - denoms[j]];
            }
        }
        result[i] %= (int)1e9 + 7;
    }
    cout << result[target];
    return 0;
}