#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> runCase(int n) {
    vector<int> result;
    vector<int> parentIndices;
    vector<int> lisIndices;
    vector<int> lis;
    vector<int> nums;
    if (n == 0) {
        return result;
    }
    for (int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        auto iter = lower_bound(lis.begin(), lis.end(), ni);
        if (lis.empty()) {
            lis.push_back(ni);
            lisIndices.push_back(i);
            parentIndices.push_back(-1);
        }
        else if (iter == lis.begin()) {
            lisIndices[0] = i;
            parentIndices.push_back(-1);
            *iter = ni;
        }
        else if (iter == lis.end()) {
            parentIndices.push_back(lisIndices[lisIndices.size() - 1]);
            lis.push_back(ni);
            lisIndices.push_back(i);
        }
        else {
            parentIndices.push_back(lisIndices[iter - lis.begin() - 1]);
            lisIndices[iter - lis.begin()] = i;
            *iter = ni;
        }
        nums.push_back(ni);
    }

    int i = lisIndices[lisIndices.size() - 1];
    while (i >= 0) {
        result.push_back(i);
        i = parentIndices[i];
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string n;
    while (getline(cin, n)) {
        vector<int> result = runCase(stoi(n));
        cout << result.size() << endl;
        for (int i = 0; i < result.size(); i++) {
            if (i != result.size() - 1) {
                cout << result[i] << " ";
            }
            else {
                cout << result[i] << endl;
            }
        }
        cin.ignore();
    }
    return 0;
}
