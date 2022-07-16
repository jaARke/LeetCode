#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long result = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        if (m.find(-ni) != m.end()) {
            result += m[-ni];
        }
        m[ni]++;
    }
    cout << result;
    return 0;
}