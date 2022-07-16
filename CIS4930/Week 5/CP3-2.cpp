#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> plots;
    vector<double> houses;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        plots.push_back(r);
    }
    for (int i = 0 ; i < m; i++) {
        double r;
        cin >> r;
        houses.push_back(r);
    }
    for (int i = 0; i < k; i++) {
        double r;
        cin >> r;
        r = sqrt(pow((r / 2.0), 2) + pow((r / 2.0), 2));
        houses.push_back(r);
    }
    sort(plots.begin(), plots.end());
    sort(houses.begin(), houses.end());

    long long count = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (plots[i] > houses[j]) {
            count++;
            j++;
        }
        if (j == houses.size()) {
            break;
        }
    }
    cout << count << endl;
    return 0;
}