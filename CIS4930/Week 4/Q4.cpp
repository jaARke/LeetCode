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
        
        priority_queue<int> negatives;  // Holds the deficit for people not already considered wealthy
        long long posSum = 0;   // Holds the total leftover money of people already considered wealthy
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
        // Go in order of people who are closest to wealthy and see if they can be made wealthy by adding some of the leftover money
        while (!negatives.empty() && posSum + negatives.top() >= 0) {
            posSum += negatives.top();
            negatives.pop();
            count++;
        }
        cout << count << endl;
    }
    return 0;
}