#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<long long> sums;
    for (int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        sums.push_back(ni);
    }
    sort(sums.begin(), sums.end());
    int i = 0;
    long long result = 1;
    while (i < sums.size() && sums[i] <= result) {
        result += sums[i];
        i++;
    }
    cout << result;
    return 0;
}