#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    int Q;
    cin >> N >> Q;

    map<int, int> courses;
    for (int i = 0; i < N; i++) {
        int s;
        int e;
        cin >> s >> e;
        courses[s] = e;
    }
    for (int i = 0; i < Q; i++) {
        int start;
        int end;
        cin >> start >> end;

        int count = 0;
        while (start < end) {
            auto iter = courses.lower_bound(start);
            if (iter == courses.end()) {
                break;
            }
            int minEnd = iter->second;
            auto minIter = iter;
            iter++;
            while (iter != courses.end()) {
                if (iter->second < minEnd && iter->second <= end) {
                    minEnd = iter->second;
                    minIter = iter;
                }
                iter++;
            }
            start = minEnd;
            count++;
            courses.erase(minIter);
        }
        cout << count << "\n"; 
    return 0;
}