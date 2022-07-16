#include <map>
#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    map<long long, long long> m;
    m[0] = 1;
    long long currSum = 0;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long ni;
        cin >> ni;
        currSum += ni;
        if (m.find(currSum - x) != m.end()) {
            result += m[currSum - x];
        }
        m[currSum]++;
    }
    cout << result;
    return 0;
}