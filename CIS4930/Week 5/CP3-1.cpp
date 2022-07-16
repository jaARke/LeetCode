#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int s;
    int c;
    int k;
    cin >> s >> c >> k;

    vector<int> socks;
    for (int i = 0 ; i < s; i++) {
        int si;
        cin >> si;
        socks.push_back(si);
    }
    sort(socks.begin(), socks.end());

    long long count = 1;
    int contained = 1;
    int lowest = socks[0];
    for (int i = 1; i < socks.size(); i++) {
        if (socks[i] - lowest > k || contained == c) {
            count++;
            contained = 1;
            lowest = socks[i];
        }
        else {
            contained++;
        }
    }
    cout << count << endl;
    return 0;
}