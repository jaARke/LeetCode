#include <iostream>
#include <algorithm>

using namespace std;

int main() {    // Kadane's Algorithm
    int n;
    cin >> n;

    int n0;
    cin >> n0;
    long long maxSum = n0, currSum = n0;
    for (int i = 1; i < n; i++) {
        long long ni;
        cin >> ni;
        currSum = max(currSum + ni, ni);
        maxSum = max(currSum, maxSum);
    }
    cout << maxSum << endl;

    return 0;
}