#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> v;
        for (int j = 0; j < n; j++) {
            int vi;
            cin >> vi;
            v.push_back(vi);
        }
        
        bool flag = true;
        long long globalCount = 0;
        while (flag) {
            long long localCount = 0;
            for (int j = 0; j < v.size() - 1; j++) {
                if (v[j] > v[j + 1]) {
                    swap(v[j], v[j + 1]);
                    localCount++;
                }
            }
            if (localCount == 0) {
                flag = false;
            }
            globalCount += localCount;
        }
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << endl << globalCount << endl;
    }
    return 0;
}