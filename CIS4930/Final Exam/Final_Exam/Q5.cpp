#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int p, s, e;
        cin >> p >> s >> e;
        v.push_back(make_pair(s, p));
        v.push_back(make_pair(e, -p));
    }
    sort(v.begin(), v.end());
    int curr = 0;
    bool flag = false;
    for (int i = 0; i < v.size(); i++) {
        curr += v.front().second;
        if (curr > c) {
            flag = true; 
            break;
        }
        v.erase(v.begin());
    }
    if (flag) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
    return 0;
}
