#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    unordered_map<int, int> counts;
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        counts[v1]++;
        counts[v2]++;
    }
    int currMin = INT32_MAX;
    int currMax = INT32_MIN;
    auto iter = counts.begin();
    while (iter != counts.end()) {
        currMin = min(currMin, iter->second);
        currMax = max(currMax, iter->second);
        iter++;
    }
    if (currMax == 2 && currMin == 1) {
        cout << "bus topology" << endl;
    }
    else if (currMax == 2 && currMin == 2) {
        cout << "ring topology" << endl;
    }
    else if (currMax == e) {
        cout << "star topology" << endl;
    }
    else {
        cout << "unknown topology" << endl;
    }
    return 0;
}