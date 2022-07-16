#include <vector>
#include <iostream>

using namespace std;

/*
This is essentially the detect islands problem. We read in the graph, and then go through it running DFS on each node we haven't seen yet (on either a previous iteration or previous DFS). Count the number
of these unfound nodes.
*/

void runDFS(int i, int j, vector<vector<char>>& graph, vector<vector<bool>>& seen) {
    // Conditions where the DFS should not continue on a given node
    if (i >= graph.size() || j >= graph[0].size() || i < 0 || j < 0 || seen[i][j] == true || graph[i][j] != '#') {
        return;
    }
    seen[i][j] = true;
    // Compute all neighbors and run DFS on each
    int nexti = i + 1;
    int nextj = j;
    runDFS(nexti, nextj, graph, seen);
    nexti = i - 1;
    runDFS(nexti, nextj, graph, seen);
    nextj = j + 1;
    runDFS(nexti, nextj, graph, seen);
    nexti = i;
    runDFS(nexti, nextj, graph, seen);
    nexti = i + 1;
    runDFS(nexti, nextj, graph, seen);
    nextj = j - 1;
    runDFS(nexti, nextj, graph, seen);
    nexti = i;
    runDFS(nexti, nextj, graph, seen);
    nexti = i - 1;
    runDFS(nexti, nextj, graph, seen);
}


int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> graph(m, vector<char>(n));
    vector<vector<bool>> seen(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            graph[i][j] = c;
        }
    }
    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == '#' && !seen[i][j]) {
                result++;
                runDFS(i, j, graph, seen);
            }
        }
    }
    cout << result << endl;
    return 0;
}