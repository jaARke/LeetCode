#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int prev, decreasing = 0, increasing = 0;
    cin >> prev;
    for (int i = 1; i < n; i++) {
        int ni;
        cin >> ni;
        if (ni < prev) {
            decreasing = increasing + 1;
        }
        if (ni > prev) {
            increasing = decreasing + 1;
        }
        prev = ni;
    }
    cout << max(increasing, decreasing) + 1 << endl;
    return 0;
}