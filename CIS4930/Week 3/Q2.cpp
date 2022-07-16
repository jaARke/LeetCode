#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a;
        int b;
        cin >> a;
        cin >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());
    int prevQual = v[0].second;
    bool happy = false;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].second < prevQual) {
            cout << "Happy Alex\n";
            happy = true;
            break;
        }
        prevQual = v[i].second;
    }
    if (!happy) {
        cout << "Poor Alex\n";
    }
    return 0;
}