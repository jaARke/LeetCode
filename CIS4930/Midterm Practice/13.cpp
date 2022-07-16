#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    deque<int> d;
    int currSum = 0, result = 0;
    for (int i = 0; i < n; i++) {
        int ni; 
        cin >> ni;
        d.push_back(ni);
        currSum += ni;
        while (currSum > m) {
            currSum -= d.front();
            d.pop_front();
        }
        result = max(result, currSum);
    }
    cout << result << endl;
    return 0;
}