#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        v.push_back(make_pair(p, c));
    }
    sort(v.begin(), v.end());
    bool happy = false;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].second < v[i - 1].second) {
            happy = true;
            break;
        }
    }
    if (happy) {
        cout << "Happy Alex";
    }
    else {
        cout << "Poor Alex";
    }
    return 0;
}