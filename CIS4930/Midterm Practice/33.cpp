#include <map>
#include <queue>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, priority_queue<int>> quests;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s[0] == 'a') {
            int e, g;
            cin >> e >> g;
            quests[e].push(g);
        }
        else {
            int q;
            long long result = 0;
            cin >> q;
            while (!quests.empty()) {
                auto iter = quests.lower_bound(q);
                while (iter == quests.end() || (iter->first > q && iter != quests.begin())) {
                    iter--;
                }
                if (iter->first > q) {
                    break;
                }
                result += iter->second.top();
                iter->second.pop();
                if (iter->second.empty()) {
                    quests.erase(iter);
                }
                q -= iter->first;
            }
            cout << result << endl;
        }
    }
    return 0;
}