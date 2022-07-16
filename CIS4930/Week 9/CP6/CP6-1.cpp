#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> managers(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int mi;
        cin >> mi;
        managers[i] = mi;
    }
    /*
    We want to find the maximum depth of the graph for all employees. We use what is essentially a depth-first search, but more simple. We just count
    the number of employees we have to go through until we get to a -1.
    */
    int result = 0;
    for (int i = 1; i <= n; i++) {
        int localResult = 1;
        int temp = managers[i];
        while (temp != -1) {
            temp = managers[temp];
            localResult++;
        }
        result = max(localResult, result);
    }
    cout << result << endl;
    return 0;
}