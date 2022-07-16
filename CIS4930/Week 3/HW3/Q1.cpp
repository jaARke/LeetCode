#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n;
    cin >> m;

    vector<long long> roomCounts;
    for (int i = 0; i < n; i++) {
        long long in;
        cin >> in;
        roomCounts.push_back(in);
    }

    int currRoom = 0;
    long long runTot = 0;
    for (int i = 0; i < m; i++) {
        long long roomNum;
        cin >> roomNum;

        while (roomNum > roomCounts[currRoom] + runTot) {
            runTot += roomCounts[currRoom];
            currRoom++;
        }
        
        cout << currRoom + 1 << " " << roomNum - runTot << "\n";
    }
    return 0;
}