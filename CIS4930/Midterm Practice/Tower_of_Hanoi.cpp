#include <iostream>
#include <vector>

using namespace std;

void recHelper(int n, int from, int to, int open, vector<pair<int, int>>& log) {
    if (n == 0) {
        return;
    }
    recHelper(n - 1, from, open, to, log);
    log.push_back(make_pair(from, to));
    recHelper(n - 1, open, to, from, log);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> log;
    recHelper(n, 1, 3, 2, log);
    
    cout << log.size() << endl;
    for (int i = 0; i < log.size(); i++) {
        cout << log[i].first << " " << log[i].second << endl;
    }

    return 0;
}