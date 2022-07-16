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
Key Insight: the answer for a node is the same for all the nodes that are passed through during a DFS of that node. Run a DFS and assign the eventual answer to all nodes passed through.
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