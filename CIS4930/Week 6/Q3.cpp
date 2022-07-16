#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int computeLISLength(vector<int>& seq) {
    vector<int> v;
    v.push_back(seq[0]);
    int result = 1;

    for (int i = 1; i < seq.size(); i++) {
        auto iter = upper_bound(v.begin(), v.end(), seq[i]);
        if (iter == v.end()) {
            result++;
            v.push_back(seq[i]);
        }
        else {
            *iter = seq[i];
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> seq;
    for (int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        seq.push_back(ni);
    }
    cout << computeLISLength(seq) << endl;
    return 0;
}