#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int d, l;
    cin >> d >> l;

    vector<long long> v;
    long long previ = 0;
    for (int i = 0; i < d; i++) {
        long long di;
        cin >> di;
        long long curr = previ + di;
        v.push_back(curr);
        previ = curr;
    }
    for (int i = 0; i < l; i++) {
        long long li;
        cin >> li;
        auto iter = lower_bound(v.begin(), v.end(), li);
        cout << iter - v.begin() + 1 << " ";
        if (iter == v.begin()) {
            cout << li << endl;
        }
        else {
            iter--;
            cout << li - *iter << endl;
        }
    }
    return 0;
}