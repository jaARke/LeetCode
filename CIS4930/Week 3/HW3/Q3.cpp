#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, priority_queue<int>> quests;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op[0] == 'a') {
            int e;
            int g;
            cin >> e;
            cin >> g;
            quests[e].push(g);
        }
        else {
            int q;
            cin >> q;
            long long gold = 0;
            while (!quests.empty()) {
                auto iter = quests.lower_bound(q);
                while (iter == quests.end() || (iter != quests.begin() && iter->first > q)) {
                    iter--;
                }
                if (!(iter->first > q)) {
                    gold += iter->second.top();
                    q -= iter->first;
                    iter->second.pop();
                    if (iter->second.empty()) {
                        quests.erase(iter);
                    }
                }
                else {
                    break;
                }
            }
            cout << gold << "\n";
        }
    }
    return 0;
}