#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int computeLISLength(vector<int>& data) {
    vector<int> v;
    v.push_back(data[0]);
    int result = 1;

    for (int i = 1; i < data.size(); i++) {
        auto iter = upper_bound(v.begin(), v.end(), data[i]);
        if (iter == v.end()) {
            result++;
            v.push_back(data[i]);
        }
        else {
            *iter = data[i];
        }
    }
    return result;
}

int computeLDSLength(vector<int> & data) {
    vector<int> v;
    v.push_back(data[data.size() - 1]);
    int result = 1;

    for (int i = data.size() - 2; i >= 0; i--) {
        auto iter = upper_bound(v.begin(), v.end(), data[i]);
        if (iter == v.end()) {
            result++;
            v.push_back(data[i]);
        }
        else {
            *iter = data[i];
        }
    }
    return result;
} 

int main() {
    vector<int> data{20, 12, 15, 26, 9, 27};
    cout << computeLISLength(data) << endl;
    cout << computeLDSLength(data) << endl;
    return 0;
}