#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fxn(vector<int>& trains) {
    if (trains.empty()) {
        return 0;
    }
    int result = 0;
    vector<int> lds;
    vector<int> lis;
    for (int i = trains.size() - 1; i > -1; i--) {
        int lisLength;
        int ldsLength;
        auto iter = upper_bound(lis.begin(), lis.end(), -trains[i]);
        if (iter == lis.end()) {
            lis.push_back(-trains[i]);
            lisLength = lis.size();
        }
        else {
            *iter = -trains[i];
            lisLength = (iter - lis.begin()) + 1;
        }
        iter = upper_bound(lds.begin(), lds.end(), trains[i]);
        if (iter == lds.end()) {
            lds.push_back(trains[i]);
            ldsLength = lds.size();
        }
        else {
            *iter = trains[i];
            ldsLength = (iter - lds.begin()) + 1;
        }
        result = max(result, (ldsLength + lisLength) - 1);
    }
    return result;
} 


int main() {
    int n;
    cin >> n;

    vector<int> trains;
    for (int i = 0; i < n; i++) {
        int ti;
        cin >> ti;
        trains.push_back(ti);
    }
    cout << fxn(trains) << endl;
    return 0;
}