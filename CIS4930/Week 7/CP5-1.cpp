#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long runCase() {
    int len;
    cin >> len;
    vector<int> seq;
    vector<long long> result(len);

    for (int j = 0; j < len; j++) {
        int seqi;
        cin >> seqi;
        seq.push_back(seqi);
    }
    for (int j = len - 1; j >= 0; j--) {
        result[j] = seq[j];
        if (j + seq[j] < len) {
            result[j] += result[j + seq[j]];
        }
    }
    return *max_element(result.begin(), result.end());
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << runCase() << endl;
    }
    return 0;
}