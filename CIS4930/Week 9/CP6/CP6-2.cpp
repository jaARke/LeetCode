#include <iostream>
#include <vector>

using namespace std;

int runDFS(vector<int>& kids, vector<int>& counts, int currDay, int start, int& count) {
    if (currDay == start) {
        counts[currDay] = count;
        return count;
    }
    count++;
    counts[currDay] = runDFS(kids, counts, kids[currDay], start, count);
    return counts[currDay];
}

/*
We run an augmented DFS which keeps track of depth of each node that is passed through while running the DFS on other nodes.
*/

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> kids(k + 1);
        for (int j = 1; j <= k; j++) {
            int ki;
            cin >> ki;
            kids[j] = ki;
        }
        vector<int> counts(k + 1, 0);
        for (int j = 1; j <= k; j++) {
            if (counts[j] == 0) {
                int count = 1;
                runDFS(kids, counts, kids[j], j, count);
            }
        }
        for (int j = 1; j <= k; j++) {
            cout << counts[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}