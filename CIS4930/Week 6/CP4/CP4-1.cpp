#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    unordered_map<int, vector<int>*> m;
    int maxL = 0;
    int maxKey = 0;
    for (int i = 0; i < n; i++) {
        int numsi;
        cin >> numsi;
        auto iter1 = m.find(numsi - 1);
        auto iter2 = m.find(numsi);
        if (iter1 != m.end()) {
            if (iter2 != m.end() && iter2->second->size() > iter1->second->size() + 1) {
                m.erase(iter1);
                continue;
            }
            iter1->second->push_back(i + 1);
            m[numsi] = iter1->second;
            m.erase(iter1);
        }
        else {
            if (iter2 != m.end()) {
                continue;
            }
            m[numsi] = new vector<int>(1, i + 1);
        }
        if (m[numsi]->size() > maxL) {
            maxL = m[numsi]->size();
            maxKey = numsi;
        }
    }
    cout << maxL << "\n";
    auto ans = m.find(maxKey)->second;
    for (int i = 0; i < ans->size(); i++) {
        cout << ans->at(i) << " ";
    }  
    return 0;
}