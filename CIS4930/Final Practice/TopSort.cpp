#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


void topSort(vector<vector<int>>& graph) {
    vector<int> counts; // Stores the number of incoming edges for a given node (prereqs)
    queue<int> q;   // Stores the current nodes for which all prereqs have been considered
    for (int i = 0; i < counts.size(); i++) {
        if (counts[i] == 0) {
            q.push(i);
        }
    }
    vector<int> res;
    while (!q.empty()) {
        res.push_back(q.front());
        auto temp = graph[q.front()];
        q.pop();
        for (int& i : temp) {
            if (--counts[i] == 0) { // Decrement incoming edges when considering a prereq
                q.push(i);
            }
        }
    }
    // If the result has as many nodes as the graph, there is no cycle
    // Result is the topological order of the graph
}