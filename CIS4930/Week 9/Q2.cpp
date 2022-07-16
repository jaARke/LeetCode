#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;


void runBFS(int i, int j, vector<vector<char>>& graph, vector<vector<bool>>& seen, int& islands) {
    queue<pair<int, int>> q;
    stack<pair<int, int>> bridgeList;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0} , {-1, 0}};

    if (graph[i][j] == 'X') {
        bridgeList.push(make_pair(i, j));
    }
    q.push(make_pair(i, j));
    seen[i][j] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nextx = x + dirs[k].first;
            int nexty = y + dirs[k].second;
            if (nextx >= 0 && nextx < graph.size() && nexty >= 0 && nexty < graph[0].size()) {
                if (graph[nextx][nexty] == 'X' && !seen[nextx][nexty]) {
                    bridgeList.push(make_pair(nextx, nexty));
                    q.push(make_pair(nextx, nexty));
                    seen[nextx][nexty] = true;
                }
                if (graph[nextx][nexty] == '#' && !seen[nextx][nexty]) {
                    q.push(make_pair(nextx, nexty));
                    seen[nextx][nexty] = true;
                }
            }
        }
    }
    while (!bridgeList.empty()) {
        int x = bridgeList.top().first;
        int y = bridgeList.top().second;
        bridgeList.pop();
        for (int k = 0; k < 4; k++) {
            int nextx = x + dirs[k].first;
            int nexty = y + dirs[k].second;
            if (nextx >= 0 && nextx < graph.size() && nexty >= 0 && nexty < graph[0].size()) {
                if (graph[nextx][nexty] == 'X' && !seen[nextx][nexty]) {
                    islands++;
                    seen[nextx][nexty] = true;
                    bridgeList.push(make_pair(nextx, nexty));
                    runBFS(nextx, nexty, graph, seen, islands);
                }
                if (graph[nextx][nexty] == 'B' && !seen[nextx][nexty]) {
                    bridgeList.push(make_pair(nextx, nexty));
                    seen[nextx][nexty] = true;
                }
            }
        }
    }
}

void findAns(vector<vector<char>>& graph, int mCount, int bridges) {
    cout << "Map " << mCount << "\n";

    vector<vector<bool>> seen(graph.size(), vector<bool>(graph[0].size(), false));
    int islands = 0;
    int buses = 0;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[0].size(); j++) {
            if (!seen[i][j] && (graph[i][j] == '#' || graph[i][j] == 'X')) {
                buses++;
                islands++;
                runBFS(i, j, graph, seen, islands);
            }
        }
    }
    cout << "islands: " << islands << "\n";
    cout << "bridges: " << bridges << "\n";
    cout << "buses needed: " << buses << "\n";
    cout << "\n";
}

int main() {
    string s;
    int mCount = 1;
    int rowCount = 0;
    int bridges = 0;
    vector<vector<char>> graph;
    while (getline(cin, s)) {
        if (s.empty()) {
            findAns(graph, mCount, bridges);
            mCount++;
            rowCount = 0;
            bridges = 0;
            graph.clear();
            continue;
        }
        vector<char> temp;
        char prev;
        for (int i = 0; i < s.length(); i++) {
            temp.push_back(s[i]);
            if (s[i] == 'B') {
                if ((rowCount > 0 && graph[rowCount - 1][i] == 'X') || prev == 'X') {
                    bridges++;
                }
            }
            prev = s[i];
        }
        graph.push_back(temp);
        rowCount++;
    }
    findAns(graph, mCount, bridges);
    return 0;
}

/*
....##..
....XX..
....BB..
....BB..
....XX..
....##..
*/

/*
...##..
...X###
...B..X
...B..B
...X..X
...####
*/

/*
..##XBBBBX##..
....B....B##..
....B....B....
....X....X....
...##....#XBX#
*/

/*
...................................
####...............................
####...............................
####...............................
####...............................
####XBBBBBBBBBBBBBBBBBX###.........
####...................###.........
####...................X##.........
####...................B...........
####...................B...........
#######################X###########
###################################
*/

/*
...X....
...B....
...X....
*/


