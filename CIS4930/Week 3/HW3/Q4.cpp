#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> arr;
        long long count = 0;
        for (int j = 0; j < n; j++) {
            int ai;
            cin >> ai;
            arr.push_back(ai);
            int k = arr.size() - 1;
            while (k > 0 && arr[k] < arr[k - 1]) {
                swap(arr[k], arr[k - 1]);
                count++;
                k--;
            }
        }
        for (int j = 0; j < arr.size(); j++) {
            cout << arr[j];
            if (j != arr.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n" << count << "\n";
    }
    return 0;
}