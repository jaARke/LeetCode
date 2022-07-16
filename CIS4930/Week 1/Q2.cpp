#include <iostream>
#include <unordered_set>

using namespace std;

bool checkTest(int n, string tasks) {
    char prev;
    unordered_set<char> prevSet;
    for (int i = 0; i < n; i++) {
        char current = tasks[i];
        if (i != 0 && current != prev) {
            if (prevSet.find(current) != prevSet.end()) {
                return true;
            }
            prevSet.emplace(prev);
        }
        prev = current;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        string tasks;
        cin >> n;
        cin >> tasks;
        if (checkTest(n, tasks)) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}