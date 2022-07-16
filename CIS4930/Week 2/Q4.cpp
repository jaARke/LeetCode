#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, int> counts;
    long long result = 0;
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (counts.find(-t) != counts.end()) {
            result += counts[-t];
        }
        counts[t]++;
    }
    cout << result << endl;
}