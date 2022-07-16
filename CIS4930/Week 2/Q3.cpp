#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    string in;
    priority_queue<string, vector<string>, greater<string> > pq;
    unordered_set<string> entered;
    while (cin >> in) {
        for (int i = 0; i < in.length(); i++) {
            if (!isalpha(in[i])) {
                string split = in.substr(0, i);
                if (split != "" && entered.find(split) == entered.end()) {
                    pq.push(split);
                    entered.insert(split);
                }
                in = in.substr(i + 1);
                i = -1;
            }
            else {
                in[i] = tolower(in[i]);
            }
        }
        if (in != "" && entered.find(in) == entered.end()) {
            pq.push(in);
            entered.insert(in);
        }
    }
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}

