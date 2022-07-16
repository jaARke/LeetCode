#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        int x;
        cin >> n;
        cin >> x;
        
        priority_queue<int> negatives;
        long long posSum = 0;
        int count = 0;
        for (int j = 0; j < n; j++) {
            int ai;
            cin >> ai;
            if (ai - x >= 0) {
                posSum += ai - x;
                count++;
            }
            else {
                negatives.push(ai - x);
            }
        }
        while (!negatives.empty() && posSum + negatives.top() >= 0) {
            posSum += negatives.top();
            negatives.pop();
            count++;
        }
        cout << count << endl;
    }
    return 0;
}